package util

import (
	"strconv"

	"github.com/tidwall/gjson"
)

// CreateClarifiPredictionRequestBody creates Prediction API input like below
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
func CreateClarifaiPredictionRequestBody(idURLMap map[string]string) PredictionRequestBody {
	// make a list of input data for creating the request model
	inputData := make([]InputData, len(idURLMap))

	// iterate over the map and instantiate structs to populate inputData
	// This is like json sample noted above modeled against the API.
	index := 0
	for k1, v1 := range idURLMap {
		inputData[index] = InputData{ImageData{URL{v1}}, k1}
		index++
	}

	// construct a PredictionRequestBody which contains necessary structs
	// with json field name definition for serializing
	return PredictionRequestBody{inputData}
}

// GetPredictionAPIResponseResult parses the response json and returns a list of prediction result
// defined in type.go
func GetPredictionAPIResponseResult(jsonBytes []byte) []PredictionResult {
	// We can also check the status code and handle that scenario.
	// names := gjson.GetBytes(jsonBytes, "status.code")
	// for i, name := range names.Array() {
	// 	// print index and value of name
	// 	log.Println("status code: ", name)
	// }

	// get outputs from the response json
	result := gjson.GetBytes(jsonBytes, "outputs")
	resultArr := result.Array()
	resultArrLength := len(resultArr)

	// iterate resultArr mapped to json outputs
	predictionResults := make([]PredictionResult, resultArrLength)
	for i, prediction := range resultArr {
		// log.Println(prediction.Raw)
		// for each prediction, get an array [input.id, ..image.url, data.concepts]
		resulti := gjson.GetMany(prediction.Raw, "input.id", "input.data.image.url", "data.concepts")

		// create conceptMap by iterating over data.concepts as an array
		conceptMap := make(map[string]float64, len(resulti[2].Array()))
		for _, data := range resulti[2].Array() {
			// only interested in name and value fields
			results := gjson.GetMany(data.Raw, "name", "value")
			// fill the map with name string and value float64
			if f, err := strconv.ParseFloat(results[1].Raw, 64); err == nil {
				conceptMap[results[0].Str] = f
			}
		}
		// for each prediction, set input id, url and conceptMap which is a map of concept and probability
		predictionResults[i] = PredictionResult{resulti[0].Str, resulti[1].Str, conceptMap}
	}

	return predictionResults

}
