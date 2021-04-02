from typing import List


class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        sums = 0
        maxans = 0
        ans = 0
        for i, num in enumerate(nums):
            sums += num
            ans += i*num
        maxans = ans
        n = len(nums)
        for num in nums:
            ans = ans-sums+num*n
            maxans = max(ans, maxans)
        return maxans
