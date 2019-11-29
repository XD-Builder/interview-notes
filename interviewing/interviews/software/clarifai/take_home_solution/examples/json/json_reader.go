package main

import (
	"encoding/json"
	"fmt"
	"github.com/tidwall/gjson"
	"io/ioutil"
	"os"
	"strconv"
)

type PredictionResult struct {
	id         string
	imageURL   string
	conceptMap map[string]float64
}

type PredictionRequestBody struct {
	Inputs []InputData `json:"inputs"`
}

type InputData struct {
	Data ImageData `json:"data"`
	Id   string    `json:"id"`
}
type ImageData struct {
	Image URL `json:"image"`
}
type URL struct {
	Url string `json:"url"`
}

func main() {
	readClarifiJson()
	// readSampleJson()

	// idURLMap := map[string]string{"A": "1", "B": "1"}
	// predictionRequestBody := createClarifiPredictionRequestBody(idURLMap)
	// fmt.Println(predictionRequestBody)
	// b, err := json.Marshal(&predictionRequestBody)
	// if err != nil {
	// 	log.Fatal(err)
	// }
	// fmt.Println(string(b))
}

// Target output
//     {
//       "inputs": [
//         {
//           "data": {
//             "image": {
//               "url": "https://samples.clarifai.com/metro-north.jpg"
//             }
//           },
//           "id": "id1"
//         },
//         {
//           "data": {
//             "image": {
//               "url": "https://c3.staticflickr.com/9/8622/16491488229_c02862eb1c_o.jpg"
//             }
//           },
//           "id": "id2"
//         }
//       ]
//     }

func createClarifiPredictionRequestBody(idURLMap map[string]string) PredictionRequestBody {
	inputData := make([]InputData, len(idURLMap))
	index := 0
	for k1, v1 := range idURLMap {
		inputData[index] = InputData{ImageData{URL{v1}}, k1}
		index++
	}
	return PredictionRequestBody{inputData}
}

func readClarifiJson() {
	// read json
	jsonFile, err := os.Open("two_image_prediction_output.json")
	if err != nil {
		fmt.Println(err)
	}

	// perform read
	// structuredRead(jsonFile)
	// unstructuredRead(jsonFile)
	// unstructuredRecursiveRead(jsonFile)
	predictionResults := unstructuredReadWithGjsonForResult(jsonFile)
	fmt.Println(predictionResults)
	defer jsonFile.Close()
}

func readSampleJson() {
	jsonFile, err := os.Open("sample.json")
	if err != nil {
		fmt.Println(err)
	}

	// perform read
	// structuredRead(jsonFile)
	// unstructuredRead(jsonFile)
	// unstructuredRecursiveRead(jsonFile)
	defer jsonFile.Close()
}

func unstructuredReadWithGjsonForResult(jsonFile *os.File) []PredictionResult {
	byteValue, _ := ioutil.ReadAll(jsonFile)

	names := gjson.GetBytes(byteValue, "status.code")
	for i, name := range names.Array() {
		// print index and value of name
		fmt.Println("at index: ", i)
		fmt.Println("status code: ", name)
	}
	result := gjson.GetBytes(byteValue, "outputs")
	resultArr := result.Array()
	resultArrLength := len(resultArr)
	// gjson.Get(result.Str)

	predictionResults := make([]PredictionResult, resultArrLength)
	for i, prediction := range resultArr {
		// fmt.Println(prediction.Raw)
		resulti := gjson.GetMany(prediction.Raw, "input.id", "input.data.image.url", "data.concepts")
		conceptMap := make(map[string]float64, len(resulti[2].Array()))
		for _, data := range resulti[2].Array() {
			results := gjson.GetMany(data.Raw, "name", "value")
			if f, err := strconv.ParseFloat(results[1].Raw, 64); err == nil {
				conceptMap[results[0].Raw] = f
			}
		}
		predictionResults[i] = PredictionResult{resulti[0].Raw, resulti[1].Raw, conceptMap}
	}

	return predictionResults
}

func unstructuredRecursiveRead(jsonFile *os.File) {
	byteValue, _ := ioutil.ReadAll(jsonFile)
	var result map[string]interface{}
	if err := json.Unmarshal([]byte(byteValue), &result); err != nil {
		return
	}
	parseMap(result)
}

func parseMap(aMap map[string]interface{}) {
	for key, val := range aMap {
		switch concreteVal := val.(type) {
		case map[string]interface{}:
			fmt.Println(key)
			parseMap(val.(map[string]interface{}))
		case []interface{}:
			fmt.Println(key)
			parseArray(val.([]interface{}))
		default:
			fmt.Println(key, ":", concreteVal)
		}
	}
}

func parseArray(anArray []interface{}) {
	for i, val := range anArray {
		switch concreteVal := val.(type) {
		case map[string]interface{}:
			fmt.Println("Index:", i)
			parseMap(val.(map[string]interface{}))
		case []interface{}:
			fmt.Println("Index:", i)
			parseArray(val.([]interface{}))
		default:
			fmt.Println("Index", i, ":", concreteVal)

		}
	}
}

func unstructuredRead(jsonFile *os.File) {
	byteValue, _ := ioutil.ReadAll(jsonFile)
	var result map[string][]interface{}
	json.Unmarshal([]byte(byteValue), &result)
	// fmt.Println(result["users"])
	for i, v := range result["users"] {
		if vMap, ok := v.(map[string]interface{}); ok {
			fmt.Println("at ", i)
			for k1, v1 := range vMap {
				fmt.Println(k1)
				if str, ok := v1.(string); ok {
					fmt.Println(str)
				} else {
					if vMap1, ok := v1.(map[string]interface{}); ok {
						for k2, v2 := range vMap1 {
							fmt.Println(k2)
							fmt.Println(v2)
						}
					}
				}
			}
		}
		// fmt.Println(result["users"][i])
	}
}

func structuredRead(jsonFile *os.File) {
	byteValue, _ := ioutil.ReadAll(jsonFile)
	var users Users
	json.Unmarshal(byteValue, &users)

	for i := 0; i < len(users.Users); i++ {
		fmt.Println("User Type: " + users.Users[i].Type)
		fmt.Println("User Age: " + strconv.Itoa(users.Users[i].Age))
		fmt.Println("User Name: " + users.Users[i].Name)
		fmt.Println("Facebook Url: " + users.Users[i].Social.Facebook)
	}
}

// Users struct which contains an array of users
type Users struct {
	Users []User `json:"users"`
}

// User struct which contains a name a type and a list of social links
type User struct {
	Name   string `json:"name"`
	Type   string `json:"type"`
	Age    int    `json:"Age"`
	Social Social `json:"social"`
}

// Social struct which contains a list of links
type Social struct {
	Facebook string `json:"facebook"`
	Twitter  string `json:"twitter"`
}
