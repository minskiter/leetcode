from typing import List, Set
from queue import Queue, LifoQueue
from collections import OrderedDict
from bisect import bisect_left
import heapq

# Solution Here


class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        m = {}
        for index, val in enumerate(intervals):
            (start, _) = tuple(val)
            m[start] = index
        keys = list(m.keys())
        rightIndex = [0]*len(intervals)
        for index, val in enumerate(intervals):
            (_, end) = tuple(val)
            find_index = bisect_left(keys, end+1)
            if find_index >= len(intervals):
                rightIndex[index] = -1
            else:
                rightIndex[index] = m[intervals[index][0]]
        return rightIndex


if __name__ == '__main__':
    pass
