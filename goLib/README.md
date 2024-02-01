## Build Golang lib on Windows

### 32-bit:

    $ProgressPreference = "SilentlyContinue"
    $GolangDistro = "go1.10.windows-386.zip"
    Invoke-WebRequest "https://go.dev/dl/$GolangDistro" -OutFile "$GolangDistro"
    Expand-Archive "$GolangDistro" -DestinationPath .

    $env:GOROOT = "$PWD\go"
    $env:PATH = $env:GOROOT + "\bin;" + $env:PATH
    $env:GOARCH = 386
    $env:GOOS = "windows"
    $env:CGO_ENABLED = 1
    $env:CC = "i686-w64-mingw32-gcc"

    go build -buildmode c-archive goLib.go

### 64-bit:

    $ProgressPreference = "SilentlyContinue"
    $GolangDistro = "go1.10.windows-amd64.zip"
    Invoke-WebRequest "https://go.dev/dl/$GolangDistro" -OutFile "$GolangDistro"
    Expand-Archive "$GolangDistro" -DestinationPath .

    $env:GOROOT = "$PWD\go"
    $env:PATH = $env:GOROOT + "\bin;" + $env:PATH
    $env:GOARCH = "amd64"
    $env:GOOS = "windows"
    $env:CGO_ENABLED = 1
    $env:CC = "x86_64-w64-mingw32-gcc"

    go build -buildmode c-archive goLib.go

## Build Golang lib on Linux

### 32-bit:

    export GOLANGDISTRO=go1.10.linux-386.tar.gz
    wget https://go.dev/dl/$GOLANGDISTRO
    sudo rm -rf /usr/local/go && sudo tar -C /usr/local -xzf $GOLANGDISTRO
    export PATH=$PATH:/usr/local/go/bin
    go version
    go build -buildmode c-archive goLib.go

### 64-bit:

    export GOLANGDISTRO=go1.10.linux-amd64.tar.gz
    wget https://go.dev/dl/$GOLANGDISTRO
    sudo rm -rf /usr/local/go && sudo tar -C /usr/local -xzf $GOLANGDISTRO
    export PATH=$PATH:/usr/local/go/bin
    go version
    go build -buildmode c-archive goLib.go
