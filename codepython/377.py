from typing import List


class Solution:

    def combinationSum4(self, nums: List[int], target: int) -> int:
        nums.sort(reverse=True)
        bag = [0] * (target+1)
        bag[0] = 1
        for i in range(1, target+1):
            for num in nums:
                if i-num >= 0:
                    bag[i] += bag[i-num]
        return bag[target]


if __name__ == "__main__":
    nums = [1, 2, 3]
    print(Solution().combinationSum4(nums, 4))
