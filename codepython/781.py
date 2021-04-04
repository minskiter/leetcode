from typing import List


class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        ans = 0
        for cnt in answers:
            ans += 1+cnt
        cnt = {}
        for i, val in enumerate(answers):
            if val in cnt and cnt[val] <= val:
                ans -= 1+val
                cnt[val]+=1
                if cnt[val]>val:
                    cnt.pop(val)
            elif val not in cnt:
                cnt[val]=1
        return ans