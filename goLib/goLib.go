package main

import "C"

import (
	"fmt"
)

//export say
func say(text *C.char) {
	fmt.Println(C.GoString(text))
}

//export fact
func fact(i int) int {
	if i <= 1 {
		return 1
	} else {
		return i * fact(i-1)
	}
}

func main() {}
