from queue import Queue
from typing import List


class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        new_level: List['Node'] = [root]
        nxt = True
        ans: List[List[int]] = [[root.val]]
        while nxt:
            nxt = False
            level = new_level
            new_level = []
            for node in level:
                if len(node.children) > 0:
                    nxt = True
                    new_level.extend(node.children)
            if nxt:
                ans.append([])
                for node in new_level:
                    ans[-1].append(node.val)
        return ans
