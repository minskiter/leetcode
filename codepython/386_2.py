from typing import List


class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        orders = [1]
        last = 1
        while len(orders) < n:
            while last*10 <= n and len(orders)<n:
                last *= 10
                orders.append(last)
            while last > 0 and last % 10 == 9:
                last //= 10         
            if len(orders) < n:
                if last+1 <= n:
                    last += 1
                    orders.append(last)
                else:
                    last = ((last//10*10+9)+1)
                    while last>10 and last%10==0:
                        last//=10
                    orders.append(last)
        return orders

