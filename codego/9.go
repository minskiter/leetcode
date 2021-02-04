package main

func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}
	var ans int64 = 0
	var temp int64 = int64(x)
	for temp > 0 {
		ans = ans*10 + temp%10
		temp /= 10
	}
	if ans != int64(x) {
		return false
	}
	return true
}

// func main() {
// 	fmt.Println(isPalindrome(10))
// }
