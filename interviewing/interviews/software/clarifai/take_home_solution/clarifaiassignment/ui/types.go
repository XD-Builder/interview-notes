package ui

// HomePage is a data type for setting variables dynamically populate the static page content
type HomePage struct {
	LabelURLRankMap map[string][]string
}

// HomePageDynamic is a type used to display dynamic home page with autocopletes
type HomePageDynamic struct {
	Labels []string
}
type PredictionAjaxRequest struct {
	Label string
}
