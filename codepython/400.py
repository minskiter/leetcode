from header import TreeNode
from typing import List, Set
from collections import OrderedDict, Counter
from queue import Queue, LifoQueue
from bisect import bisect_left
import heapq


class Solution:
    def findNthDigit(self, n: int) -> int:
        s = 0
        i = 9
        si = 0
        cnt = 1
        while s+(i*cnt) < n:
            s += i*cnt
            si += i
            i *= 10
            cnt += 1
        rest = (n-s) % cnt
        if rest==0:
            rest = cnt
        tmp = si+(n-s+cnt-1)//cnt
        for j in range(cnt-rest):
            tmp //= 10
        return tmp % 10


if __name__ == '__main__':
    pass
