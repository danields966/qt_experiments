## Build Golang lib on Windows

### 32-bit:

    $ProgressPreference = "SilentlyContinue"
    $GolangFolder = "go1.20.windows-386"
    $GolangDistro = "$GolangFolder.zip"
    Invoke-WebRequest "https://go.dev/dl/$GolangDistro" -OutFile "$GolangDistro"
    Expand-Archive "$GolangDistro" -DestinationPath $GolangFolder

    $env:GOROOT = "$PWD\$GolangFolder\go"
    $env:PATH = "$PWD\..\..\mingw32\bin;" + $env:PATH
    $env:PATH = $env:GOROOT + "\bin;" + $env:PATH
    $env:GOARCH = 386
    $env:GOOS = "windows"
    $env:CGO_ENABLED = 1
    $env:CC = "i686-w64-mingw32-gcc"

    go build -o goLib32.a -buildmode c-archive goLib.go

### 64-bit:

    $ProgressPreference = "SilentlyContinue"
    $GolangFolder = "go1.20.windows-amd64"
    $GolangDistro = "$GolangFolder.zip"
    Invoke-WebRequest "https://go.dev/dl/$GolangDistro" -OutFile "$GolangDistro"
    Expand-Archive "$GolangDistro" -DestinationPath $GolangFolder

    $env:GOROOT = "$PWD\$GolangFolder\go"
    $env:PATH = "$PWD\..\..\mingw64\bin;" + $env:PATH
    $env:PATH = $env:GOROOT + "\bin;" + $env:PATH
    $env:GOARCH = "amd64"
    $env:GOOS = "windows"
    $env:CGO_ENABLED = 1
    $env:CC = "x86_64-w64-mingw32-gcc"

    go build -o goLib64.a -buildmode c-archive goLib.go

To build lib for Windows XP, use Golang distro `go1.10.windows-386.zip` for 32-bit or `go1.10.windows-amd64.zip` for 64-bit

## Build Golang lib on Linux

### 32-bit:

    export GOLANGDISTRO=go1.20.linux-386.tar.gz
    wget https://go.dev/dl/$GOLANGDISTRO
    sudo rm -rf /usr/local/go && sudo tar -C /usr/local -xzf $GOLANGDISTRO
    export PATH=$PATH:/usr/local/go/bin
    go version
    go build -o goLib32.a -buildmode c-archive goLib.go

### 64-bit:

    export GOLANGDISTRO=go1.20.linux-amd64.tar.gz
    wget https://go.dev/dl/$GOLANGDISTRO
    sudo rm -rf /usr/local/go && sudo tar -C /usr/local -xzf $GOLANGDISTRO
    export PATH=$PATH:/usr/local/go/bin
    go version
    go build -o goLib64.a -buildmode c-archive goLib.go
