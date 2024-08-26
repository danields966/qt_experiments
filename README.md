# qt-experiments

## Qt 5.15 static build instructions for Windows host:

### Supported targets:

* windows-i386
* windows-amd64
* macos-amd64
* macos-arm64
* linux-i386
* linux-amd64
* linux-arm64

#### Set target OS for docker building

    $TARGET = "windows-i386"

#### Build the Docker image using the following command

    docker build -t qt-$TARGET -f Dockerfile.$TARGET .

#### Run the Docker container if you want to interact with it

    docker run -it -d --name qt-$TARGET qt-$TARGET /bin/bash

#### To copy Qt distro to host run

    docker cp qt-${TARGET}:/usr/local/Qt-5.15 Qt-5.15-$TARGET

## Build qt-experiments inside Docker

#### Bind to bash inside container

    docker exec -it qt-$TARGET /bin/bash

#### Run inside container 

    cd /opt/qt-experiments/
    qmake qt-experiments.pro
    make -j $(nproc)
    exit

#### To copy executable to host run:

* Unix build

        docker cp qt-${TARGET}:/opt/qt-experiments/qt-experiments qt-experiments-$TARGET

* Windows build

        docker cp qt-${TARGET}:/opt/qt-experiments/release/qt-experiments.exe qt-experiments-${TARGET}.exe

* MacOS build

        docker cp qt-${TARGET}:/opt/qt-experiments/qt-experiments.app qt-experiments-${TARGET}.app
