package ranking

// ImageRank models image its possible concepts for sorting
type ImageResult struct {
	URL string
	// conceptValueMap map[string]float64
	Index int
	Value float64
}
