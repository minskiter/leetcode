package main

func twoSum(nums []int, target int) []int {
	ans := []int{0, 0}
	numMap := map[int]int{}
	for index, num := range nums {
		result := target - num
		if numMap[result] > 0 {
			ans[0] = numMap[result]
			ans[1] = index + 1
			break
		}
		if numMap[num] == 0 {
			numMap[num] = index + 1
		}
	}
	ans[0]--
	ans[1]--
	return ans
}

// func main() {
// 	fmt.Printf("%v", twoSum([]int{2,7,11,15}, 9))
// }
