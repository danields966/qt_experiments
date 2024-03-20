# qt-experiments

## Qt 5.15 static build instructions for Linux amd64:

    # Build the Docker image using the following command:
    docker build -t qt_linux_amd64 -f Dockerfile.linux-amd64 .
    # Run the Docker container:
    docker run -d --name qt_linux_amd64 qt_linux_amd64
    # Copy the file from the container to host:
    docker cp qt_linux_amd64:/usr/local/Qt-5.15 Qt-5.15-linux-amd64
    # Run bash in container if necessary
    docker run -it qt_linux_amd64 /bin/bash
