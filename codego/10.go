package main

import (
	"regexp"
)

func isMatch(s string, p string) bool {
	matched, _ := regexp.MatchString("^"+p+"$", s)
	return matched
}

// func main() {
// 	fmt.Println(isMatch("mississippi", "mis*is*p*."))
// }
