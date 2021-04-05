from typing import List, Set
from queue import Queue, LifoQueue
import heapq

# Solution Here


class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        m = set()
        for i in intervals:
            for j in i:
                m.add(j)
        m = list(m)
        m.sort()
        rev_m = dict(zip(m, [x for x in range(len(m))]))
        m = dict(zip([x for x in range(len(m))], m))
        interval_dict = {}
        for i in intervals:
            if i[1] not in interval_dict:
                interval_dict[i[1]] = []
            interval_dict[i[1]].append(i[0])
        dp = [0]*(len(m))
        for i in range(len(dp)):
            if i in m and m[i] in interval_dict:
                for j in interval_dict[m[i]]:
                    dp[i] = max(dp[i], dp[rev_m[j]]+1)
            dp[i] = max(dp[i], dp[i-1])
        return len(intervals)-dp[len(dp)-1]


if __name__ == '__main__':
    print(Solution().eraseOverlapIntervals([[1, 2], [2, 3]]))
