package main

import (
	"bytes"
)

func convert(s string, numRows int) string {
	cycle := numRows*2 - 2
	if cycle == 0 {
		cycle = 1
	}
	var buffer bytes.Buffer
	lens := len(s)
	for row := 0; row < numRows; row++ {
		for times := 0; times*cycle+row < lens; times++ {
			buffer.WriteByte(s[times*cycle+row])
			if !(row == 0 || row == numRows-1) {
				if times*cycle+cycle-row < lens {
					buffer.WriteByte(s[times*cycle+cycle-row])
				}
			}
		}
	}
	return buffer.String()
}

// func main() {
// 	fmt.Println(convert("ABCD", 3))
// }
