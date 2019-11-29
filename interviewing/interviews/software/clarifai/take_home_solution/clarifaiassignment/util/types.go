package util

// Request Model
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

// Response Model
type PredictionResult struct {
	ID         string
	ImageURL   string
	ConceptMap map[string]float64
}

// ImageRank models image its possible concepts for sorting
type ImageResult struct {
	PredictionResult PredictionResult
	Index            int
	Value            float64
}
