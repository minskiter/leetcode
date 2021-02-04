package main

func lengthOfLongestSubstring(s string) int {
	lastMap := map[rune]int{}
	ans := 0
	length := 0
	for index, ch := range s {
		if lastMap[ch] != 0 && index+1-lastMap[ch] <= length {
			length = index + 1 - lastMap[ch]
		} else {
			length++
		}
		lastMap[ch] = index + 1
		if length > ans {
			ans = length
		}
	}
	return ans
}

// func main() {
// 	fmt.Printf("%v", lengthOfLongestSubstring(""))
// }
