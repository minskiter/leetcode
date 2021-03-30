class Solution:
    def firstUniqChar(self, s: str) -> int:
        cnt = {}
        for c in s:
            if c in fir:
                cnt[c]+=1
            else:
                cnt[c]=1
        for index,c in enumerate(s):
            if cnt[c]==1:
                return index
        return -1