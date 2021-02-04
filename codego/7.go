package main

import (
	"math"
)

func reverse(x int) int {
	x64 := int64(x)
	var f int64 = 1
	if x64 < 0 {
		f = -1
		x64 = -x64
	}
	var ans int64
	for ; x64 > 0; x64 /= 10 {
		ans = ans*10 + x64%10
	}
	if ans*f > math.MaxInt32 || ans*f < math.MinInt32 {
		ans = 0
	}
	return int(ans * f)
}

// func main() {
// 	fmt.Println(reverse(2137384647))
// }
