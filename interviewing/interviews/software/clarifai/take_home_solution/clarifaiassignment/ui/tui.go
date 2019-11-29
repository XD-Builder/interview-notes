package ui

import (
	"bufio"
	"clarifaiassignment/util"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const labelsPerLine = 10

// RunInteractiveTUI lists all available labels and asks user to type in labels
// for matching and display useful info about image
func RunInteractiveTUI(predictionResultMap map[string][]util.ImageResult) {
	// setup and info messages
	reader := bufio.NewReader(os.Stdin)
	labels := make([]string, 0, len(predictionResultMap))
	for k := range predictionResultMap {
		labels = append(labels, k)
	}
	fmt.Println("Available Labels are: ")
	printLabel(labels)
	fmt.Println("\nTo search images, type the label name.")
	fmt.Println("To exit, type 'exit'.")

	for {
		// print prompt and get input
		fmt.Print("$ ")
		label, err := reader.ReadString('\n')
		if err != nil {
			fmt.Fprintln(os.Stderr, err)
		}
		label = strings.TrimSpace(label)
		// debug messages
		// fmt.Println("label is ", label)
		// fmt.Println("label size ", len(label))
		// fmt.Println(predictionResultMap[label])
		// fmt.Println(len(predictionResultMap[label]))

		if label == "exit" {
			os.Exit(0)
		}
		// if label input provided by the user is empty, then print help
		if len(predictionResultMap[label]) == 0 {
			fmt.Println("Unable to find label, please enter a different one", label)
			fmt.Println("available labels are: ")
			printLabel(labels)
		} else {
			// a label is found and we will print ranked image URLs and their possibilities
			fmt.Println("key: ", label)
			for i, imageResult := range predictionResultMap[label] {
				fmt.Println("\t: rank ", strconv.Itoa(i+1), "URL ", imageResult.PredictionResult.ImageURL,
					"Probability: ", fmt.Sprintf("%f", imageResult.PredictionResult.ConceptMap[label]))
			}
			fmt.Println("Press <ENTER> to get a list of labels")
		}
	}
}

// format the label so it it's more readable
func printLabel(labels []string) {
	fmt.Print("\t")
	for i, label := range labels {
		fmt.Print(label, ", ")
		if (i+1)%labelsPerLine == 0 {
			fmt.Print("\n\t")
		}
	}
	fmt.Println()
}
