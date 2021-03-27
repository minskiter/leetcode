from typing import List
import heapq


class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        pos = (0, 0)
        queue = []
        heapq.heappush(queue, (matrix[0][0], pos))
        while k > 0:
            item = heapq.heappop(queue)
            k -= 1
            if item[0] == 0 and item[1][0]+1 < len(matrix):
                heapq.heappush(
                    queue, (matrix[item[1][0]+1][item[1][1]], (item[1][0]+1, item[1][0])))
            if item[1][1]+1 < len(matrix[0]):
                heapq.heappush(queue, (matrix[item[1][0]][item[1][1]+1], (item[1][0], item[1][1]+1))
        return heapq.heappop(queue)[0]
