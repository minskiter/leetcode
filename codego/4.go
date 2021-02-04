package main

// import "fmt"

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	p := 0
	p1 := 0
	p2 := 0
	lenNums1 := len(nums1)
	lenNums2 := len(nums2)
	total := lenNums1 + lenNums2
	for p1 < lenNums1 && p2 < lenNums2 {
		p++
		if nums1[p1] < nums2[p2] {
			// select nums1
			if p >= (total+1)/2 {
				if (total & 1) == 1 {
					return float64(nums1[p1])
				}
				// compare next
				if p1+1 < lenNums1 && nums1[p1+1] < nums2[p2] {
					return float64(nums1[p1]+nums1[p1+1]) / 2.0
				}
				return float64(nums1[p1]+nums2[p2]) / 2.0
			}
			p1++
		} else {
			// select nums2
			if p >= (total+1)/2 {
				if (total & 1) == 1 {
					return float64(nums2[p2])
				}
				// compare next
				if p2+1 < lenNums2 && nums2[p2+1] < nums1[p1] {
					return float64(nums2[p2]+nums2[p2+1]) / 2.0
				}
				return float64(nums2[p2]+nums1[p1]) / 2.0
			}
			p2++
		}
	}
	for ; p1 < lenNums1; p1++ {
		p++
		if p >= (total+1)/2 {
			if (total & 1) == 1 {
				return float64(nums1[p1])
			}
			return float64(nums1[p1]+nums1[p1+1]) / 2.0
		}
	}
	for ; p2 < lenNums2; p2++ {
		p++
		if p >= (total+1)/2 {
			if (total & 1) == 1 {
				return float64(nums2[p2])
			}
			return float64(nums2[p2]+nums2[p2+1]) / 2.0
		}
	}
	return 0.0
}

// func main() {
// 	fmt.Println(findMedianSortedArrays([]int{2}, []int{}))
// }
