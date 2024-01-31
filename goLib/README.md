Run:

    $env:GOROOT="C:\Users\Daniel\go\go1.10"
    $env:PATH+=$env:GOROOT+"\bin"
    $env:GOARCH=386
    $env:GOOS="windows"
    $env:CGO_ENABLED=1
    $env:CC="i686-w64-mingw32-gcc"

    go build -buildmode c-archive goLib.go
