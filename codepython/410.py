from header import TreeNode
from typing import List, Set
from collections import OrderedDict, Counter
from queue import Queue, LifoQueue
from bisect import bisect_left
import heapq


class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        left = 0
        right = 1 << 31
        mininum = sum(nums)
        while left <= right:
            mid = left+(right-left)//2
            canSplit = True
            s = 0
            cnt = 1
            for num in nums:
                if num > mid:
                    canSplit = False
                if s+num > mid:
                    s = 0
                    cnt += 1
                s += num
            if cnt > m:
                canSplit = False
            if canSplit:
                mininum = mid
                right = mid-1
            else:
                left = mid+1
        return mininum


if __name__ == '__main__':
    pass
