class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child


class Solution:
    last: 'Node' = None

    def flatten(self, head: 'Node') -> 'Node':
        if head == None:
            return None
        last = head
        head.next = self.flatten(head.next)
        if head.child != None:
            last.next, head.next = head.next, self.flatten(head.child)
        return head
