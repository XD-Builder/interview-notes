# Clarifai Tech Product Notes
## Overview
* Clarifai API Intro
    * Provides image and video recognition as a service, which recognizes visual content by classifying them.
    * Prediction type is based on model you run input through. Thus if running your input through 'food' model will return predictions with concepts that 'food' model knows.
    * All API access is over HTTPS via `https://api.clarifai.com`
* Status Code
    * [URL](https://clarifai.com/developer/status-codes/) to get a list of status code for all API calls
* Predict
    * What does it do?
        * Analyzes your images or videos and returns concepts back with their corresponding probabilities.
    * Image Prediction via URL
        * You can supply an image via URL or uploading to get predictions.
    * Videos
        * the Predict API response will return a list of predicted concepts for every frame of video and video is processed at 1 frame per second.
* Search
    * Uses predicted concepts on images to power search
    * Steps to perform search from scratch
        * Add images to search index.
            * It can be done by supplying an image to the API with max 128 images in one API call.
        * Search By Concept
            * Once your images are indexed, you can query search by concept
        * Search By Image
            * You can also search images using another image by providing an image or url.
* Train
    * Why train?
        * A model will only see the concepts it contains. There are times when you wish you had a model and train it with your own images and concepts. You create your own model and train it with your own images and concepts. Once trained, you can use it to make predictions
    * Add images with concepts
        * First add images that already contain the concepts you want your model to see by posting it to inputs API
    * Create A Model
        * Once your images with concepts are added, you are now ready to create a model by posting it to models API
        * The "model/id" returned is important and needs to be used for train and predict the model
    * Train The Model
        * So far, you have provided input images and created model with concepts available. The next step is to train the model and tell the system to look at all the images with concepts you've provided and learn from them.
        * The Train API call is async and takes few seconds to be fully trained and ready.
        * You train the model by posting to the model/id generated previously along with a version.
    * Predict With The Model
        * To predict we need to specify model id, version, and input image we want to get predictions from.
* Workflow
    * New entity added which encompasses one or more Public or Custom model(s).
    * With Workflow Predict you will be able to reduce the latency and in turn make your product more efficient.
* Evaluate
    * You use evaluate to test performance of your trained model before using it in the production environment. It allows you to perform a cross validation on a specified model version.

## Glossary
* Application => A kind of self contained workspace for your search indexes and custom models. A search performed in one app will return results from images within that same app.
* Concept => like "tag" or "keyword" that describes the input and there are two types. Those you can specify to train a model, and those that a model assigns as a prediction.
* Embeddings => low dimensional representation of a model's input that has rich semantic info.
* Explorer => Web app to view Clarifai app
* Input => Usually an image and they can be saved and searched later.
* Model => Provides heavy lifting to convert inputs to predictions.
* Operation => An action that is performed via API or UI. It can include predictions, searches, input uploads, training custom models, model evaluations and more.
* Prediction => Predictions returned after going through a specific model. It's model dependent.
* Search => Finding relevant images in your app by text(concepts match), reverse image search (similar-looking images), or both
* Train => Update a model to "learn" from all the image concepts you have provided in your app. Anytime you add/update image concepts, you can use "train" again to create a new model version, fit to the latest information.
* Workflow => enables users to make predictions on one or more public/custom models, with a single API call.
