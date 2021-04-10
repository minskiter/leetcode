from header import TreeNode
from typing import List, Set
from collections import OrderedDict, Counter
from queue import Queue, LifoQueue
from bisect import bisect_left
import heapq


class Solution:
    def longestPalindrome(self, s: str) -> int:
        cnts = Counter()
        for ch in s:
            cnts[ch] += 1
        ans = 0
        for key in cnts:
            if (cnts[key] & 1) == 1 and (ans & 1) == 0:
                ans += 1
            ans += (cnts[key] & 0)
        return ans


if __name__ == '__main__':
    pass
