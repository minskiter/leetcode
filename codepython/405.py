from header import TreeNode
from typing import List, Set
from collections import OrderedDict, Counter
from queue import Queue, LifoQueue
from bisect import bisect_left
import heapq


class Solution:
    def toHex(self, num: int) -> str:
        if num < 0:
            num += (1 << 32)
        if num==0:
            return '0'
        s = ""
        while num > 0:
            if num % 16 >= 10:
                s = chr(num % 16-10+ord('a'))+s
            else:
                s = chr(num % 16+ord('0'))+s
            num//=16
        return s


if __name__ == '__main__':
    print(Solution().toHex(-1))
