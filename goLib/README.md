## Build Golang lib on Windows

## Build Golang lib on OS X

### 64-bit:

    export GOLANGDISTRO=go1.20.darwin-amd64.tar.gz
    wget https://go.dev/dl/$GOLANGDISTRO
    sudo rm -rf /usr/local/go && sudo tar -C /usr/local -xzf $GOLANGDISTRO
    export PATH=$PATH:/usr/local/go/bin
    go version
    go build -buildmode c-archive goLib.go
