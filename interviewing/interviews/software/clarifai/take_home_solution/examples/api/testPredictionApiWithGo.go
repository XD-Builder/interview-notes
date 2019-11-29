package main

import (
	"bytes"
	"errors"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"os"
	"strings"
)

const apiKey string = "API_KEY"
const modelID string = "MODEL_ID"
const modelVersion string = "MODEL_VERSION"
const env string = "ENVIRONMENT"
const prodEnvName string = "PROD"
const urlFormat string = "https://api.clarifai.com/v2/models/%s/versions/%s/outputs"
const clarifaiS3ImageURL string = "https://s3.amazonaws.com/clarifai-data/backend/api-take-home/images.txt"

func main() {
	// set up
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

	// get clarifai S3 bucket image urls
	resp, err := callClarifaiS3ImageURL()
	if err != nil {
		log.Fatal(err)
	}
	response := string(resp)
	imageUrls := strings.Split(response, "\n")
	log.Println("Number of images in S3: ", len(imageUrls))
	for _, image := range imageUrls[:10] {
		log.Println(image)
	}

	// call Clarifai Prediction API
	url := fmt.Sprintf(urlFormat, modelIDi, modelVersioni)
	resp, err = callPredictionAPI(url, nil)
	if err != nil {
		log.Fatal(err)
	}

	log.Println(resp)
}

func callClarifaiS3ImageURL() ([]byte, error) {
	// call and defer resource release
	resp, err := http.Get(clarifaiS3ImageURL)
	if err != nil {
		return nil, err
	}
	defer resp.Body.Close()

	// convert and check status
	body, err := ioutil.ReadAll(resp.Body)
	if resp.StatusCode != http.StatusOK {
		return nil, errors.New("Unexpected Status Code: " + string(resp.StatusCode) + ", content" + string(body))
	}

	return body, nil
}

func callPredictionAPI(url string, postData []byte) ([]byte, error) {
	// setting up
	log.Println("Calling url: ", url)
	client := &http.Client{}
	req, err := http.NewRequest("POST", url, bytes.NewReader(postData))

	if err != nil {
		return nil, err
	}
	req.Header.Add("User-Agent", "myClient")

	// calling
	resp, err := client.Do(req)
	if err != nil {
		return nil, err
	}
	defer resp.Body.Close()
	body, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		return nil, err
	}

	if resp.StatusCode != http.StatusOK {
		return nil, errors.New("Unexpected Status Code: " + string(resp.StatusCode) + ", content" + string(body))
	}

	return body, nil
}
