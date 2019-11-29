# Abstract

- This project aims to solve Clarifai's take-home coding design question using Golang with environment definitions specified in a Dockerfile

## How to run the project

- cd to mvp project and for each Dockerfile, add your API key
- run ./runApp.sh
  - Before you run, check following settings in mvp/app.go
    _ Set imagesPerRequest to a low number and isRequestAllImages to false to test out ui/gui quickly.
    _ Then you can test all images in s3 by running `git reset --hard` \* Current solution is not parallelized with goroutine and batch requests takes time for 1000 images sequentially

<pre>
// limit for each image request batch to prediction api, should not exceed 128 images
const imagesPerRequest int = 100

// the top k of the ranked images to be displayed, k set to 10 now
const rankImageSize = 10

// bool to set to send all 1000 requests, if false send only the limit set by imagesPerRequestLimit.
const isRequestAllImages = true

</pre>

# Coding Design Question Overview - By Clarifai

## Background

- Say you were assigned to a product team that wants to build a search engine for images, and the team wants to see a simple working example in Golang.

## Requirement for MVP

- Tag each image found in [this file](https://s3.amazonaws.com/clarifai-data/backend/api-take-home/images.txt) using the HTTP API (docs)[https://clarifai.com/developer/docs/], and store the results in an in-memory data structure. Note: Do not use the (search function)[https://clarifai.com/developer/guide/search#search] of the API; you should only need to use the (predict endpoint)[https://clarifai.com/developer/guide/predict#predict] in your solution.
- Provide a very simple interface (e.g. read from STDIN, HTML page with search box, or GUI) that repeatedly reads in a string tag name and returns a sorted list of at most 10 of the most probable images.

## Additional Requirement

- Include an explanation for any inefficiencies with this MVP and any possible improvements that could be made.
- Include with your solution the exact commands to build and run your program. If you submit a Dockerized solution, it needs to be based on publicly accessible base image and the Dockerfile should not make assumptions about the system on which the image is built and run.

## Comments

- Use basic HTTP requests to make requests to Clarifai
- Use Golang
- Zip up this project for submission

# Coding Solution Design - By Harold

## Implementation Overview

1. A static Web UI with Bootstrap responsive UI and autocomplete that runs on localhost:8080
   1. Only provides initial HTML and the following interaction will be purely on the client side
2. A dynamic Web UI with Bootstrap responsive UI and autocomplete that runs on localhost:8080
   1. Makes ajax call to go server
3. A TUI that runs on a shell interactively
4. Sorting
   - Priority Queue implemented in Max Heap is used to increase performance if n gets too large and k image to rank is small.
     - Tested and the biggest overhead actually comes from object instantiation and memory allocation
   - Quick Sort can be used to rank top K elements and it will be faster in best case.
5. A nested result object used by GUI and TUI
   - Designed data structure `map[string][]util.ImageResult` and each `util.ImageResult` contains information about that image such as `ID, ImageURL, concepts`. Concept is large but thinking that in the future you can probably use concepts to get "additional details" on the image one selected, I choose to include this in the structure and thus can be a little bit complex to navigate this nested structure.
6. API usage
   - I choose to set an imagesPerRequestLimit variable to a lower level so that I don't spend too much API call every time I run.
   - Note that a user can have 5,000 max API call and the S3 bucket file has 1000 image file.
   - I won't be able to finish the project if I set it to run 1000 images
7. Implementation Comments
   - Since there is no requirement for fuzzy search or word distance match, a map is used to perform O(1) find operation
   - A decision was made to use qjson to extract elements rather than a model for faster adaption to api response changes.
     - Performance can be slower compared to iterating over the nodes.
   - Modular Design, performance and maintainability are emphasized in overall design.
8. What would you do differently next time?
   - Use an IDE or VSCode for TDD, debugging and navigation supports instead of a vim terminal with a vim-go plugin. This would save a lot of time without the need to run the entire app to find/fix a problem.
   - Better design the code layout. Instead of putting types in ui or util and using clarifaiassignment as the package name, there may be better ways to do it.
   - Experiment with goroutine and channel to make batch requests concurrently instead of inside a for loop utilizing RWMutex possibly.
   - Better structure the gui and make it more responsive with transitions or fade ins instead of directly displaying the image and background image stub when images are not fully loaded.
