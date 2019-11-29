package ui

import (
	"clarifaiassignment/util"
	"encoding/json"
	"html/template"
	"log"
	"net/http"
	"path"
)

const homeHTMLStatic = "home-static.html"
const homeHTMLDynamic = "home-dynamic.html"

var predictionResultMap map[string][]util.ImageResult

var templateHomeStatic = path.Join("templates", homeHTMLStatic)
var templateHomeDynamic = path.Join("templates", homeHTMLDynamic)

// avoids template reloading with template initialized as global
var templates = template.Must(template.ParseFiles(templateHomeStatic, templateHomeDynamic))

// entry points -- start
func RunGUIStatic(inputMap map[string][]util.ImageResult) {
	predictionResultMap = inputMap
	http.HandleFunc("/", handleDefaultStatic)
	runServerAtPort8080()
}

func RunGUIDynamic(inputMap map[string][]util.ImageResult) {
	predictionResultMap = inputMap
	http.HandleFunc("/", handleDefaultDynamic)
	http.HandleFunc("/predict", handlePrediction)
	runServerAtPort8080()
}

// handler -- start
func handlePrediction(w http.ResponseWriter, r *http.Request) {
	var PredictionAjaxRequest PredictionAjaxRequest
	err := json.NewDecoder(r.Body).Decode(&PredictionAjaxRequest)
	if err != nil {
		http.Error(w, err.Error(), http.StatusInternalServerError)
	}

	predictionResultList := predictionResultMap[PredictionAjaxRequest.Label]
	log.Println("prediction result list length is", len(predictionResultList))
	var urls []string
	for _, imageResult := range predictionResultList {
		urls = append(urls, imageResult.PredictionResult.ImageURL)
	}
	log.Println("Got", PredictionAjaxRequest.Label, "returning", urls)

	// create json response from struct
	a, err := json.Marshal(urls)
	if err != nil {
		http.Error(w, err.Error(), http.StatusInternalServerError)
	}
	w.Write(a)
}

func handleDefaultDynamic(w http.ResponseWriter, r *http.Request) {
	keys := make([]string, len(predictionResultMap))
	i := 0
	for k := range predictionResultMap {
		keys[i] = k
		i++
	}

	homePageDynamic := HomePageDynamic{Labels: keys}
	if err := templates.ExecuteTemplate(w, homeHTMLDynamic, homePageDynamic); err != nil {
		http.Error(w, err.Error(), http.StatusInternalServerError)
	}
}

func handleDefaultStatic(w http.ResponseWriter, r *http.Request) {
	log.Println("A request is received from ip", r.RemoteAddr)

	labelURLRankMap := make(map[string][]string)
	for k, v := range predictionResultMap {
		for _, imageResult := range v {
			labelURLRankMap[k] = append(labelURLRankMap[k], imageResult.PredictionResult.ImageURL)
		}
	}

	// create home page with label to a list of image urls for display
	homePage := HomePage{LabelURLRankMap: labelURLRankMap}

	// avoids template reloading with template initialized as global
	if err := templates.ExecuteTemplate(w, homeHTMLStatic, homePage); err != nil {
		http.Error(w, err.Error(), http.StatusInternalServerError)
	}
}

func runServerAtPort8080() {
	log.Println("Started server at port 8080")
	log.Println("Mapped Endpoint / to home page")
	log.Println("Start testing now! Go to localhost:8080/.")
	log.Fatal(http.ListenAndServe(":8080", nil))
}
