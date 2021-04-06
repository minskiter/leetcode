from header import TreeNode
from typing import List, Set
from collections import OrderedDict, Counter
from queue import Queue, LifoQueue
from bisect import bisect_left
import heapq

# Solution Here


class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        cnt = Counter()
        for ch in p:
            cnt[ch] += 1
        n = len(p)
        ans = 0
        for index, ch in enumerate(s):
            if index >= n:
                cnt[ch] += s[index-n]
                if cnt[ch] == 0:
                    del cnt[ch]
            else:
                cnt[ch] -= s[index-n]
                if cnt[ch] == 0:
                    del cnt[ch]
            if index>=n-1:
                if len(cnt)==0:
                    ans+=1
        return ans


if __name__ == '__main__':
    pass
