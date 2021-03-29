from typing import List

class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        orders = []
        stack = [(1, 8)]
        while len(stack) > 0:
            orders.append(stack[-1][0])
            (last, step) = stack.pop()
            if last+1 <= n and step > 0:
                stack.append((last+1, step-1))
            if last*10 <= n:
                stack.append((last*10, step*10))
        return orders
