package main

// import (
// 	"fmt"
// )

func longestPalindrome(s string) string {
	maxLength := 0
	maxR := 0
	lens := len(s)
	f := func(l int, r int) {
		for l >= 0 && r < lens && s[l] == s[r] {
			if r-l+1 > maxLength {
				maxLength = r - l + 1
				maxR = r + 1
			}
			l--
			r++
		}
	}
	for index := range s {
		f(index, index)
		f(index, index+1)
	}
	if maxLength > 0 {
		return s[maxR-maxLength : maxR]
	}
	return ""
}

// func main() {
// 	fmt.Println(longestPalindrome("bab"))
// }
