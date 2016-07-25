// http://www.darkcoding.net/software/building-shared-libraries-in-go-part-2
// go build -buildmode=c-shared -o libconcat.so concat.go

package main

import "C"

//export Concat
func Concat(sIn string, bIn []byte, bOut []byte) {
	n := copy(bOut, sIn)
	copy(bOut[n:], bIn)
}

func main() {}
