from typing import List, Set


class Solution:
    def canCross(self, stones: List[int]) -> bool:
        dp: List[Set[int]]= [set() for i in len(stones)]
        dp[0] = {1}
        for index, stone in enumerate(stones):
            for j in range(index):
                dis = stone-stones[j]
                for d in range(dis-1, dis+2, 1):
                    if d in dp[j]:
                        dp[index].add(dis)
                        break
        return len(dp[-1]) > 0
