# Abstract

- This document introduces docker and dockerfile, its syntax and usage.

## Docker Components

1. Docker Daemon
   1. Interacts with Docker Client to receive commands and start container.
   2. Interacts with Docker Hub to download, pull and push images.
2. Docker Client
   1. Interacts with Docker Daemon for commands it wish to send.
3. Docker Hub
   1. Commands from Docker client is sent to Docker Daemon, which then interprets the command executes it. Also called Docker Registry.
   2. It is where you can find a list of public Docker images created by developers for your use.

## Docker Info

1. Docker Ports
   1. When you type `docker ps` if you see an entry with PORTS "80/tcp", it means that port 80 is being exposed by the Container. That means there is Dockerfile which has two entries "EXPOSE 80" and it means port 80 is exposed
2. Committing your image - steps
   1. Launch your container and without the --rm flag
   2. Update the container OS dependencies and make customization
   3. Exit the container and you should see your container name with `docker ps -all` in an exited state
   4. Now commit the container image via docker commit command
      1. docker commit [container_id]repository[:Tag]]
      2. repository format is recommended as <dockerhubusername>/<repositoryname>
      3. Ex. docker commit mycontainer1 rominirani/ubuntu-git
         1. This creates and returns an image id which can be launched.
            1. Ex. docker run -it --name c1 rominirani/ubuntu-git
         2. You can also push this image to Docker Hub
            1. Ex. docker push rominirani/ubuntu-git
            2. Now you can search with `docker search ubuntu-git`
3. Pushing images to local registry
   1. Set up local registry
      1. docker run -d -p 5000:5000 --name localregistry registry
      2. This downloads the registry run it on port 5000
   2. To pull images from local registry
      1. Ex. docker pull localhost:5000/alpine
         1. Pulls the alpine
         2. Specifies registry as [REGISTRY_HOSTNAME:REGISTRY_PORT]/IMAGENAME where the initial part is optional for local registry that the docker client will look for.
   3. To push local images into local registry
      1. run `docker image` to get a list of images
      2. run `docker tag alpine:latest localhost:5000/alpine:latest` to tag local image to local registry image tag
      3. run `docker push localhost:5000/alpine:latest` to push the tagged local registry image to remote
4. Docker Volume
   1. Data Volumes
      1. About
         1. A data volume is a specially designed directory in the container.
         2. It is initialized when the container is created. By default it is not deleted when the container is stopped. It is not even garbage collected when there is no container referencing the volume.
         3. The data volumes are independently updated. Data volumes can be shared across containers too, They could be mounted in read-only mode too.
      2. Mounting a data volume
         1. Ex. `docker run -it -v /data --name container1 busybox`
         2. It creates a data directory under the root directory inside the container. You can inspect it and find that mounted volume /data is mapped /var/lib/docker/volumes/hash/\_data folder
      3. Removing a mounted volume
         1. Ex. `docker rm container1` won't remove the volume created by it. Run `docker volume ls` and it will show the volume still.
         2. Ex `docker rm -v container1` will remove the volume and container altogether.
   2. Mounting a Host Directory as a Data volume
      1. Ex. `docker run -it --name container1 -v /Users:/datavol busybox`
      2. It runs container and maps /Users folder to container /data/vol folder
   3. Data volume containers
      1. A useful way to share data between containers or to use the data from non-persistent containers. It involves first creating a Data volume container, then create another container and mount the volume from the container created previously.
      2. Ex. `docker run -it -v /data --name container1 busybox`
         1. Creates a container called container1 and mount a volume inside that
         2. Then `cd data` and create files inside that directory
         3. If you run `docker exec container1 ls /data` in a separate window, you will see the files listed.
      3. Ex. `docker run -it --volumes-from container1 --name container2 busybox`
         1. --volumes-from <container_name> tells container2 to mount the volumes that container1 mounted.
         2. now run `cd data` and you will see two files created previously to be there

## Docker Advanced

1. Linking Docker Containers
   1. How to build a web server container with a link to a database server?
      1. run `docker pull redis`
      2. run `docker run -d --name redis1 redis` to create redis container in detached mode
      3. run `docker run -it --link redis1:redis --name redisclient1 busybox` to link redis1 to client
         1. The --link flag is sourcecontainername:containeraliasname. **redis1 is the source container name and container alias name has been selected as redis** and it could be any name
         2. An entry is added to /etc/hosts file of redisclient1 for the alias of redis1 and its ip. Thus pinging redis will resolve to the ip defined in /etc/hosts file.
         3. Environment variable are auto-created to help reach redis1 server from redisclient1
         4. Now since the redis is connected one can install redis-cli and run `redis-cli -h redis` to connect to redis and set key and values.
         5. One can run other containers and link to redis1 and get redis value using key.

## Write a Dockerfile

1. Why Dockerfile?
   1. One can build an image via running a Container, installing software and doing a commit. However, writing a Dockerfile is a more **consistent and repeatable way** to build your image.
   2. A Dockerfile is a text file which has a series of instructions on how to build your image. It supports a simple set of commands that you need to use in your Dockerfile.
      1. Example commands are `FROM CMD ENTRYPOINT VOLUME ENV`.
      2. Overflow is like this:
         1. Create a Dockerfile with the required instructions
         2. Use the docker build command to create a Docker image based on the Dockerfile that you created in step 1
2. To build a custom image
   1. First create a Dockerfile with all required customization
   2. Then run `docker build -t image_name:tag_name .` to build the image.
   3. Lastly, run `docker run -it image_name`
3. To configure a Dockerfile
   1. CMD ["executable", "param1", "param2"]
      1. It runs the command as the executable and it prints out data of the command when you run the container.
      2. We can override the default CMD by providing it at the command line a program such as /bin/bash to run.
   2. ENTRYPOINT
      1. Used to configure a container to run as an executable. It specifies the default app that you want to run.
      2. If a CMD command is placed after ENTRYPOINT command, its argument becomes a list of parameters to that ENTRYPOINT application. The CMD params can be overriden at CLI.
      3. Ex. `ENTRYPOINT [“/bin/cat”]` followed by `CMD [“/etc/passwd”]` in a Dockerfile.
         1. You can build this image file and run `docker run -it myimage` you will be seeing passwd catted on the screen
         2. You can also override the default CMD by running `docker run -it myimage somefile.txt` which will try cat a non-existent file.
   3. RUN & EXPOSE
      1. RUN is a directive to execute any commands which will update the image to a specific state when build.
      2. EXPOSE is a directive to inform what port the container will be listening on.
   4. COPY
      1. Copies the files/folders from the source to the destination in the container during build

## Docker Swarm

1. What is?
   1. A container orchestration system for building, shipping and running containers at scale. The list of software that currently provides this capability include **Kubernetes, Docker Swarm, Apache Mesos and other**.
2. Why Container Orchestration System?
   1. If you have hundreds of containers, you need to be able easily see if they are running in a distributed mode. Some features required include
      1. Health checks on the containers
      2. Launching a fixed set of containers for a particular Docker image
      3. Scaling the number of Containers up and down depending on the load.
      4. Performing rolling update of software across container and more.
3. Create Docker Machines
   1. The first step to create a set of Docker machines that will act as nodes in your Docker Swarm.
   2. Ex. `docker-machine create --driver hyperv manager1` or `docker-machine create --driver virtualbox manager1`
      1. Depending on the environment in which you run your Docker Swarm, you choose the corresponding driver, hyperv for windows and virtualbox for Docker Toolbox
4. List Docker machines
   1. Ex. `docker-machine ls`
      1. Lists name of the docker container running, their driver url and states.
      2. `docker-machine ip manager1` will show the ip address for the container name.
      3. `docker-machine ssh <machine-name>` allows you to ssh into a container.
5. Create Swarm Cluster
   1. After you have created several containers via docker-machine, we can proceed with setting up the Swarm.
   2. Ex. `docker-machine ssh manager1`, then `docker swarm init --advertise-addr MANAGER_IP`
      1. The first thing to initialize Swarm is to ssh into the manager1 machine and initialize the Swarm in there.
      2. You can find your swarm status by running `docker node ls` and other nodes can join the swarm as a worker or a manager.
6. Join Docker Swarm as Worker or Manager Node
   1. run `docker swarm join-token worker` to find out the join command to join as a worker.
   2. run `docker swarm join-token manager` to find out the join command to join as a manager
   3. To set up Swarm, ssh into each individual containers and run the command to join as worker so that the manager1 container can find joined workers by running `docker node ls`
7. Create a Service
   1. Once the swarm is up and running, manager can run containers for us and will take care of scheduling them, sending/distributing commands to them.
   2. To start a service
      1. You need to have a Docker image that you want to run.
      2. You will expose service on a port say 80
      3. You will specify the number of containers to launch, specified via the **replicas** parameter.
      4. Decide on the name of the service.
   3. Ex. `docker service create --replicas 5 -p 80:80 --name web nginx`
      1. Run the command inside the manager1 container and the orchestration layer will now do the work. If you run `docker service ls` you will find a service named web with 5 replicas with image nginx running.
      2. Run the command `docker service ps web` and it will show you the state of slave nodes running.
8. Scaling up and down
   1. `Docker service scale` command is used to perform scaling.
   2. If you currently have 5 containers running and you want to bump it up to 8 you can run `docker service scale web=8`
   3. inspecting nodes
      1. You can inspect Swarm nodes at anytime via docker node inspect command. Ex. `docker node inspect self` or `docker node inspect worker1`
9. Draining a node
   1. If a node is ACTIVE, it is ready to accept tasks from the Master i.e. Manager.
   2. If a node is active, per documentation, it can receive new tasks when:
      1. during a service update to scale up
      2. during a rolling update
      3. when you set another node to Drain availability
      4. when a task fails on another active node
   3. To drain a node
      1. Ex. `docker node update --availability drain worker1 worker1`
      2. sets availability of a node to drain and this will cause `docker service ps web` to show that containers on worker1 are being rescheduled on other workers.
10. Remove a service
    1. `docker service rm web`, then `docker service ls`, then `docker service inspect web`
       1. Command 1 will remove service web, then service ls will show all running services and inspect will find no service named web because it's already been removed.
11. Apply rolling updates
    1. run `docker service update --image <imagename>:<version> web`
    2. This will update the image for a service to a different image with a different version

## Docker commands

1. docker run hello-world
   1. It asks the docker to download the 'hello-world' image and run it.
   2. Here docker client looked for an image titled 'hello-world' in your local repo and it then went to the Internet and hit a URL at Docker Registry because local repo doesn't the image. Once the image is found on the remote registry, it launched an instance(container) based on that image
2. docker images
   1. List all existing images and their attributes, including REPOSITORY and TAG. REPOSITORY is the name of the Image itself and TAG is the latest is the version specified. If the command `docker run IMAGE` does not specify ":TAG" after "IMAGE", then "latest" is implicitly used by the Docker client in the absence of an explicit tag
   2. Thus, "$ docker run -t -i busybox" will be translated to "$ docker run -t -i busybox:latest"
   3. To get a specific version, ex., run "\$ docker run -t -i busybox:1.0"
   4. Show all images you downloaded from remote registries.
3. docker ps -a
   1. List all running containers
   2. Fields & definitions
      1. CONTAINER_ID is a unique ID for the container launched
      2. IMAGE is an image that you launched
      3. COMMAND is the default command that is executed when the container is launched.
4. docker help
   1. List commands that the docker client can understand.
5. docker COMMAND --help
   1. List subcommands and options on a specific command.
6. docker version
   1. Show the current docker version
7. docker info
   1. Show several pieces of information about the OS
8. docker search busybox
   1. Search the online Docker registry for an image named busybox
9. docker run -it -d --name xyz -P busybox
   1. Instantiate a container in mirror of the busybox image. Then run it interactively and attach to tty input.
   2. -d param runs the container in detached mode
   3. --name provides a name instead of a default provided by docker
   4. -P allows for a expose the internal container port to an external host random port.
   5. --rm remove instance upon exit
10. docker images
11. docker start -i eb5eda8d9857
    1. Relaunch a container with container id eb5eda8d9857
    2. -i option allows going into interactive mode.
    3. docker attach eb5eda8d9857
       1. Attach to container_id eb5eda8d9857 if it's not started in interactive mode.
12. docker stop eb5eda8d9857
    1. Stop container id eb5eda8d9857.
13. docker pull httpd
    1. Download the Docker image to your local repo and don't run it.
14. docker rm MyWebServer
    1. removes a docker container which must be already stopped
15. docker inspect container1
    1. outputs a JSON about the container
16. docker volume ls
    1. Lists the volumes available
17. docker build -t image_name:tag_name directory
    1. Builds an image with a tag using a Dockerfile specified in a directory so that you can run docker run -it image_name to start a new container.
18.
