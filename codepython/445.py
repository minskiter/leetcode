from header import TreeNode, ListNode
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
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        len1, len2 = 0, 0
        p = l1
        while p != None:
            len1 += 1
            p = p.next
        p = l2
        while p != None:
            len2 += 1
            p = p.next
        if len1 < len2:
            l1, l2 = l2, l1
            len1, len2 = len2, len1
        p1, p2 = l1, l2
        for i in range(len1-len2):
            p1 = p1.next
        while p1 != None:
            p1.val += p2.val
            p1 = p1.next
            p2 = p2.next
        pre = ListNode(0, l1)
        p = pre
        cur = l1
        while cur != None:
            if cur.val == 9:
                cur = cur.next
            elif cur.val > 9:
                while pre != cur:
                    pre.val = (pre.val+1) % 10
                    pre = pre.next
                cur.val %= 10
                cur = cur.next
            else:
                pre = cur
                cur = cur.next
        if p.val == 0:
            p = p.next
        return p


if __name__ == '__main__':
    pass
