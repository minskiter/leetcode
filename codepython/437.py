from header import TreeNode
from typing import List, Set
from collections import OrderedDict, Counter
from queue import Queue, LifoQueue
from bisect import bisect_left
import heapq


# Solution Here
class Solution:
    def pathSum(self, root: TreeNode, s: int) -> int:
        sum_map = Counter()
        ans = 0

        def path(root):
           if root == Node:
                return Counter()
            c = Counter()
            c[root.val]+=1
            left = path(root.left)
            for key in left:
                c[key+root.val] += left[key]
            right = path(root.right)
            for key in right:
                c[key+root.val]+=right[key]
            ans+=c[s]
            return c
        return ans


if __name__ == '__main__':
    pass
