Background
Let’s say that you were assigned to a product team that wants to build a search engine for images, and that team wants to see a simple working example in Golang.

Challenge
Your task is to design and implement an MVP that will:
* Tag each image found in [this file](https://s3.amazonaws.com/clarifai-data/backend/api-take-home/images.txt) using the HTTP API [docs](https://clarifai.com/developer/docs/), and store the results in an in-memory data structure. Note: Do not use the [search function](https://clarifai.com/developer/guide/search#search) of the API; you should only need to use the [predict endpoint](https://clarifai.com/developer/guide/predict#predict) in your solution.
* Provide a very simple interface (e.g. read from STDIN, HTML page with search box, or GUI) that repeatedly reads in a string tag name and returns a sorted list of at most 10 of the most probable images.

Please include an explanation of any inefficiencies with this MVP (Minimum Viable Product) and any possible improvements that could be made.

Please include with your solution the exact commands to build and run your program. If you submit a Dockerized solution, it needs to be based on a publicly accessible base image and the Dockerfile should not make assumptions about the system on which the image is built and run.

Comments
Since we don't have an updated API Client in Golang, you need to use basic HTTP requests (as opposed to using API clients).
Learning is a part of daily life as a software engineer. If you don’t know Golang, we encourage you to spend some time and give it a try.
This exercise is an open book and an individual assignment. You should not seek help from others.
Take your time and provide a thoughtful solution.
When you are finished, zip up your project files and submit using the link below.
