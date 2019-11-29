package main

import (
	"fmt"
	"sort"
	"strconv"
	"time"

	"./ranking"
)

const numImages int = 80000000

func main() {
	start := time.Now()
	// sortUsingPriorityQueue()
	sortUsingSlice()
	fmt.Println("Time spent: ", time.Since(start))
}

// with const numImages int = 80,000,000
// Time creating array of images  9.944930763s
// A79999999
// 7.9999999e+07
// A79999998
// 7.9999998e+07
// Time spent:  21.391686581s
func sortUsingSlice() {
	start := time.Now()
	var imageResults []ranking.ImageResult = make([]ranking.ImageResult, numImages)
	for i := 0; i < numImages; i++ {
		var imageResult ranking.ImageResult
		imageResult.URL = "A" + strconv.Itoa(i)
		imageResult.Value = float64(i)
		imageResults[i] = imageResult
	}
	fmt.Println("Time creating array of images ", time.Since(start))

	sort.Slice(imageResults, func(i, j int) bool { return imageResults[i].Value > imageResults[j].Value })

	for i := 0; i < 2; i++ {
		fmt.Println(imageResults[i].URL)
		fmt.Println(imageResults[i].Value)
	}
}

// with const numImages int = 80,000,000
// Time creating array of images  11.58725051s
// Time spent creating priorityQueue:  300.783055ms
// Time spent initializing heap:  5.052594899s
// Time spent getting kth largest element from heap:  5.492µs
// A79999999
// 7.9999999e+07
// A79999998
// 7.9999998e+07
// Time spent:  16.942594609s
func sortUsingPriorityQueue() {
	start := time.Now()
	// It takes too long to create array of pointers to image result.
	// Compared to using Slice
	var imageResults []ranking.ImageResult = make([]ranking.ImageResult, numImages)
	for i := 0; i < numImages; i++ {
		var imageResult ranking.ImageResult
		imageResult.URL = "A" + strconv.Itoa(i)
		imageResult.Value = float64(i)
		imageResults[i] = imageResult
	}
	fmt.Println("Time creating array of images ", time.Since(start))
	result := ranking.TopRankPriorityQueueFullQueue(imageResults, 2)

	for _, i := range result {
		fmt.Println(i.URL)
		fmt.Println(i.Value)
	}
}
