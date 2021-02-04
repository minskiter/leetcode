package main

func maxArea(height []int) int {
	min := func(a int, b int) int {
		if a < b {
			return a
		}
		return b
	}
	lens := len(height) - 1
	l := 0
	r := lens
	ans := 0
	for l < r {
		minHeight := min(height[l], height[r])
		temp := minHeight * (r - l)
		if temp > ans {
			ans = temp
		}
		if l+1 >= lens {
			r--
		} else if r-1 < 0 {
			l++
		} else if height[l] < height[r] {
			l++
		} else {
			r--
		}
	}
	return ans
}

// func main() {
// 	fmt.Println(maxArea([]int{1, 3, 2, 5, 25, 24, 5}))
// }
