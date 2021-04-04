class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        cnt = {}
        ans = 0
        for num in nums:
            rev = int(str(num)[::-1])
            rev = num-rev
            if rev not in cnt:
                cnt[rev]=1
            else:
                ans=(ans+cnt[rev])%1000000007
                cnt[rev]+=1
        return ans