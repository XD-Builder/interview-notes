#!/bin/bash

# Allows you to choose which ui to run
echo "do you want to run TUI, GUI-STATIC, or GUI-DYNAMIC (t/g/G)"
read choice
if [ "$choice" == "t" ]; then
    echo "building docker images clarifaiassignment:tui-v1"
    docker build -t clarifaiassignment:tui-v1 -f dockerfiles/Dockerfile.tui .
    echo "Running clarifaiassignment interactively in text user interface"
    docker run -it clarifaiassignment:tui-v1
elif [ "$choice" == "g" ]; then
    echo "building docker images gui-static-v1"
    docker build -t clarifaiassignment:gui-static-v1 -f dockerfiles/Dockerfile.gui-static .
    echo "Running clarifaiassignment in graphical user interface - web static"
    docker run -it -p 8080:8080/tcp clarifaiassignment:gui-static-v1
elif [ "$choice" == "G" ]; then
    echo "building docker images gui-dynamic-v1"
    docker build -t clarifaiassignment:gui-dynamic-v1 -f dockerfiles/Dockerfile.gui-dynamic .
    echo "Running clarifaiassignment in graphical user interface - web dynamic"
    docker run -it -p 8080:8080/tcp clarifaiassignment:gui-dynamic-v1
else
    echo "you did not make a valid choice, exiting..."
fi

