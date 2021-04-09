from header import TreeNode
from typing import List, Set
from collections import OrderedDict, Counter
from queue import Queue, LifoQueue
from bisect import bisect_left
import heapq


class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people = sorted(people, key=lambda p: (p[1], p[0]))
        construct_people = []
        for p in people:
            greater = 0
            index = -1
            for index, c in enumerate(construct_people):
                if c[0] >= p[0]:
                    greater += 1
                if greater > p[1]:
                    index -= 1
                    break
            construct_people.insert(index+1, p)
        return construct_people


if __name__ == '__main__':
    print(Solution().reconstructQueue(
        [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]))
