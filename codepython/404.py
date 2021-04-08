from header import TreeNode
from typing import List, Set
from collections import OrderedDict, Counter
from queue import Queue, LifoQueue
from bisect import bisect_left
import heapq

class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        if root==None:
            return 0
        s = 0
        if root.right!=None:
            s+=self.sumOfLeftLeaves(root.right)
        if root.left!=None:
            if root.left.left==None and root.left.right==None:
                s+=root.val
            else:
                s+=self.sumOfLeftLeaves(root.left)
        return s
        

if __name__=='__main__':
    pass