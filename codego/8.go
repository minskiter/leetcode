package main

import (
	"math"
)

func myAtoi(s string) int {
	var ans int64 = 0
	var f int64 = 1
	first := true
	for _, ch := range s {
		if ch == '-' || ch == '+' {
			if !first {
				break
			}
			if ch == '-' {
				f = -1
			}
			first = false
		} else if ch >= '0' && ch <= '9' {
			first = false
			ans = ans*10 + int64(ch-'0')
			if ans*f > math.MaxInt32 {
				return math.MaxInt32
			} else if ans*f < math.MinInt32 {
				return math.MinInt32
			}
		} else if ch != ' ' {
			if first {
				return 0
			}
			break
		} else if ch == ' ' {
			if !first {
				break
			}
		}
	}
	return int(ans * f)
}

// func main() {
// 	fmt.Println(myAtoi(" 0 4192 with 22"))
// }
