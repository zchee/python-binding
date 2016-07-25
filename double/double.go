// http://www.darkcoding.net/software/building-shared-libraries-in-go-part-1
// go build -o libdouble.so -buildmode=c-shared double.go
// python
//  >>> import ctypes
//  >>> lib = ctypes.CDLL("libdoubler.so")
//  >>> lib.DoubleIt(21)
//  42
package main

import "C"

//export DoubleIt
func DoubleIt(x int) int {
	return x * 2
}

func main() {}
