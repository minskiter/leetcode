from typing import List


class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        s = sum(nums)
        if (s&1)!=0:
            return False
        tp = s//2
        dp = [False]*(tp+1)
        dp[0] = True
        for num in nums:
            for index, has in enumerate(dp):
                if has and index+num <= tp:
                    dp[index+num] = True
            if dp[tp]:
                return True
        return False
