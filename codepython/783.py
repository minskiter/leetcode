from header import TreeNode
from typing import List, Set, Tuple
from collections import OrderedDict, Counter
from queue import Queue, LifoQueue
from bisect import bisect_left
import heapq


def inside(pos: Tuple[int, int], leftTop: Tuple[int, int], rightBottom: Tuple[int, int]):
    if pos[0] < leftTop[0] or pos[0] >= rightBottom[0] or pos[1] < leftTop[1] or pos[1] >= rightBottom[1]:
        return False
    return True


def add_tuple(x: Tuple[int, int], y: Tuple[int, int]):
    return (x[0]+y[0], x[1]+y[1])


class Solution:
    def minDiffInBST(self, root: TreeNode) -> int:
        data = [1e6, 1e6]

        def dfs(root: TreeNode, data: List[int]):
            if root == None:
                return
            dfs(root.left)
            data[0] = min(data[0], abs(root.val-data[1]))
            data[1] = root.val
            dfs(root.right)

        dfs(root)
        return data[0]


if __name__ == '__main__':
    pass
