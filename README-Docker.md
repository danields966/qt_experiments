# qt-experiments

## Qt 5.15 static build instructions for Linux amd64:

    # Build the Docker image using the following command:
    docker build -t qt_linux_amd64 -f Dockerfile.linux-amd64 .
    # Run the Docker container:
    docker run -it -d --name qt_linux_amd64 qt_linux_amd64 /bin/bash
    # Copy the file from the container to host:
    docker cp qt_linux_amd64:/usr/local/Qt-5.15 Qt-5.15-linux-amd64

### Build project inside Docker

    docker exec -it qt_linux_amd64 /bin/bash
    # Run inside container
    cd /opt/qt-experiments/
    qmake qt-experiments.pro
    make
    exit
    # Copy execulable to host
    docker cp qt_linux_amd64:/opt/qt-experiments/qt-experiments qt-experiments-linux-amd64

## Qt 5.15 static build instructions for Linux i386:

    # Build the Docker image using the following command:
    docker build -t qt_linux_i386 -f Dockerfile.linux-i386 .
    # Run the Docker container:
    docker run -it -d --name qt_linux_i386 qt_linux_i386 /bin/bash
    # Copy the file from the container to host:
    docker cp qt_linux_i386:/usr/local/Qt-5.15 Qt-5.15-linux-i386

### Build project inside Docker

    docker exec -it qt_linux_i386 /bin/bash
    # Run inside container
    cd /opt/qt-experiments/
    qmake qt-experiments.pro
    make
    exit
    # Copy execulable to host
    docker cp qt_linux_i386:/opt/qt-experiments/qt-experiments qt-experiments-linux-i386
