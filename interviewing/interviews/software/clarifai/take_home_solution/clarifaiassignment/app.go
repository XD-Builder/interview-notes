package main

import (
	"bytes"
	"clarifaiassignment/ui"
	"clarifaiassignment/util"
	"encoding/json"
	"errors"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"os"
	"strconv"
	"strings"
)

const uiType string = "UI_TYPE"
const apiKey string = "API_KEY"
const modelID string = "MODEL_ID"
const modelVersion string = "MODEL_VERSION"
const env string = "ENVIRONMENT"
const prodEnvName string = "PROD"
const urlFormat string = "https://api.clarifai.com/v2/models/%s/versions/%s/outputs"
const clarifaiS3ImageURL string = "https://s3.amazonaws.com/clarifai-data/backend/api-take-home/images.txt"

// limit for each image request batch to prediction api, should not exceed 128 images
const imagesPerRequest int = 100

// the top k of the ranked images to be displayed, k set to 10 now
const rankImageSize = 10

// bool to set to send all 1000 requests, if false send only the limit set by imagesPerRequestLimit.
const isRequestAllImages = true

func main() {
	ui := os.Getenv(uiType)
	if ui == "TUI" {
		runTUI()
	} else if ui == "GUI-STATIC" {
		runGUIStatic()
	} else if ui == "GUI-DYNAMIC" {
		runGUIDynamic()
	}
}

// Runs Dynamic Web UI with only possible labels stored in the html page
// Then client makes Ajax calls to prediction endpoint for image urls
func runGUIDynamic() {
	log.Print("Welcome to Clarifai Dynamic Web Interface...")
	log.Println("Starting to set up a ranked model for search")
	predictionResultMap := getPredictionResultMap()
	log.Println("All images are labeled")
	ui.RunGUIDynamic(predictionResultMap)
}

// Runs Static Web UI where Webpage itself contains all image urls and ranking
// can be heavy on client side to store all that data in a page. Slow loading time.
func runGUIStatic() {
	log.Print("Welcome to Clarifai Static Static Web Interface...")
	log.Println("Starting to set up a ranked model for search")
	predictionResultMap := getPredictionResultMap()
	log.Println("All images are labeled")
	ui.RunGUIStatic(predictionResultMap)
}

// Runs a interactive terminal program where it displays all possible labels
// You can type a label and it will return you corresponding images and values
func runTUI() {
	log.SetOutput(ioutil.Discard)
	fmt.Print("Welcome to Clarifai TUI...")
	fmt.Println("Starting to set up a ranked model for search")
	predictionResultMap := getPredictionResultMap()
	fmt.Println("All images are labeled")
	ui.RunInteractiveTUI(predictionResultMap)
}

// makes call to S3 and Clarifai prediction api to generate a
// map string to a list of sorted imageResult on probability
func getPredictionResultMap() map[string][]util.ImageResult {
	// if environment is empty or not prod then we should print out apiKey and other information about the request
	apiKeyi := os.Getenv(apiKey)
	modelIDi := os.Getenv(modelID)
	modelVersioni := os.Getenv(modelVersion)
	environment := os.Getenv(env)
	log.Println("Current environment is set to ", environment)
	if !strings.EqualFold(environment, prodEnvName) {
		log.Println(apiKey, " ", apiKeyi)
		log.Println(modelID, " ", modelIDi)
		log.Println(modelVersion, " ", modelVersioni)
	}

	// get clarifai S3 bucket image urls, and exit if any error
	respBytes, err := getClarifaiS3Images()
	if err != nil {
		log.Fatal(err)
	}

	// trim to fix one more extra empty line problem, from 1001 lines to 1000 lines
	response := strings.TrimSpace(string(respBytes))

	// split responses by newline
	imageURLs := strings.Split(response, "\n")
	log.Println("Number of images in S3: ", len(imageURLs))

	// imagesPerRequest defined as a constant for each http batch image request
	idURLMap := make(map[string]string, imagesPerRequest)
	var idURLMaps []map[string]string
	for i, imageURL := range imageURLs {
		// set up image id and put this image id with its corresponding image url
		// to the idURLMap which will be used later for making requests
		id := "ImageRequest-" + strconv.Itoa(i)
		idURLMap[id] = imageURL

		// continue accumulate idURLMap with id and imageURLs until the following:
		// 		if going over imagesPerRequest limit
		// 		append the idURLMap to idURLMaps, then make a new map
		if (i+1)%imagesPerRequest == 0 {
			// log.Println("called at index", strconv.Itoa(i))
			idURLMaps = append(idURLMaps, idURLMap)
			idURLMap = make(map[string]string, imagesPerRequest)
			// 	if it's the last image
		} else if i == len(imageURLs) {
			//	append the idURLMap to idURLMaps
			idURLMaps = append(idURLMaps, idURLMap)
		}
	}
	// debugging urls if needed.
	// log.Println(len(idURLMaps))
	// for i, idURLMap := range idURLMaps {
	// 	log.Println(i)
	// 	log.Println(len(idURLMap))
	// }

	// rankMap is the model decided for containing all the ranking result.
	rankMap := make(map[string][]util.ImageResult)

	// constant defined in this go file to avoid calling all of the
	// 1000 images if isRequestAllImages is set to false
	if isRequestAllImages {
		// iterate over the list of idURLMap, each contains max imagesPerRequest image id
		// and image urls. It will then call API get response and add labels and imageResult
		// structs to the rankMap's keys and values list respectively.
		for _, idURLMap := range idURLMaps {
			// set up body, url, and make a request to the api
			bodyBytes := getPredictionRequestBody(idURLMap)
			url := fmt.Sprintf(urlFormat, modelIDi, modelVersioni)
			respBytes, err = callPredictionAPI(url, apiKeyi, bodyBytes)
			if err != nil {
				log.Fatal(err)
			}

			// Parse Response
			predictionResults := util.GetPredictionAPIResponseResult(respBytes)

			// generate a rankMap which contains keys, which are names or concepts
			// and values, which are imageResult struct defined in the util package
			for _, predictionResult := range predictionResults {
				for k, v := range predictionResult.ConceptMap {
					// for each item in an image prediction, generate an image
					imageResult := util.ImageResult{PredictionResult: predictionResult, Index: 0, Value: v}
					rankMap[k] = append(rankMap[k], imageResult)
				}
			}
		}
	} else {
		// convert request into prediction request API body
		bodyBytes := getPredictionRequestBody(idURLMaps[0])

		// call Clarifai Prediction API
		url := fmt.Sprintf(urlFormat, modelIDi, modelVersioni)
		respBytes, err = callPredictionAPI(url, apiKeyi, bodyBytes)
		if err != nil {
			log.Fatal(err)
		}

		// Parse Response
		predictionResults := util.GetPredictionAPIResponseResult(respBytes)

		// Generate Rank Map
		// Map will consist of concept as key, and value as all array
		for _, predictionResult := range predictionResults {
			for k, v := range predictionResult.ConceptMap {
				imageResult := util.ImageResult{PredictionResult: predictionResult, Index: 0, Value: v}
				rankMap[k] = append(rankMap[k], imageResult)
			}
		}

	}

	// rank top N images in the rankMap for each labels. Top K or top len(map)
	for k, v := range rankMap {
		rankMap[k] = util.RankTopKImage(v, min(rankImageSize, len(rankMap[k])))
		// 	log.Println("key: ", k)
		// 	for i, imageResult := range v {
		// 		log.Println("\t: rank ", i, "URL ", imageResult.PredictionResult.ImageURL,
		// 			"Probability: ", fmt.Sprintf("%f", imageResult.PredictionResult.ConceptMap[k]))
		// 	}
	}

	return rankMap
}

func getPredictionRequestBody(idURLMap map[string]string) []byte {
	// generate a predictionRequestBody which contains type definition
	// for serializing into a json file
	predictionRequestBody := util.CreateClarifaiPredictionRequestBody(idURLMap)
	log.Println("Generating Request Body", predictionRequestBody)

	// marshal the requestbody struct and return the []byte
	// b, err := json.MarshalIndent(&predictionRequestBody, "", "    ")
	b, err := json.Marshal(&predictionRequestBody)
	if err != nil {
		log.Fatal(err)
	}
	return b
}

func getClarifaiS3Images() ([]byte, error) {
	// http get s3 images and defer response body release
	resp, err := http.Get(clarifaiS3ImageURL)
	if err != nil {
		return nil, err
	}
	defer resp.Body.Close()

	// read all response body inputstream in []bytes and return error if the response body can't be read
	body, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		return nil, err
	}

	// check valid status code not 200 and print status code and content body read previously
	if resp.StatusCode != http.StatusOK {
		return nil, errors.New("Unexpected Status Code: " + string(resp.StatusCode) + ", content" + string(body))
	}

	return body, nil
}

func callPredictionAPI(url string, apiKey string, postData []byte) ([]byte, error) {
	// create a post request to the url with data
	log.Println("Calling url: ", url)
	client := &http.Client{}
	req, err := http.NewRequest("POST", url, bytes.NewReader(postData))
	if err != nil {
		return nil, err
	}

	// set authorization and content type headers
	req.Header.Add("Authorization", "Key "+apiKey)
	req.Header.Add("Content-Type", "application/json")

	// make a http post call
	resp, err := client.Do(req)
	if err != nil {
		return nil, err
	}
	defer resp.Body.Close()

	// check error reading body
	body, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		return nil, err
	}

	// check valid status code not 200 and print status code and content body read previously
	if resp.StatusCode != http.StatusOK {
		return nil, errors.New("Unexpected Status Code: " + string(resp.StatusCode) + ", content" + string(body))
	}

	return body, nil
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
