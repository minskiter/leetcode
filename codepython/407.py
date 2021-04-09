from header import TreeNode
from typing import List, Set
from collections import OrderedDict, Counter
from queue import Queue, LifoQueue
from bisect import bisect_left
import heapq


from typing import List, Set
from collections import OrderedDict, Counter
from queue import Queue, LifoQueue
from bisect import bisect_left
import heapq


class Solution:
    def inside(self, x, leftTop, rightBottom):
        if x[0] < leftTop[0] or x[0] >= rightBottom[0] or x[1] < leftTop[1] or x[1] >= rightBottom[1]:
            return False
        return True

    def tuple_add(self, x, y):
        return (x[0]+y[0], x[1]+y[1])

    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        q = []
        dir = [(0, 1), (1, 0), (-1, 0), (0, -1)]
        vis = [[False for i in heightMap[0]] for j in heightMap]
        for i in range(len(heightMap)):
            heapq.heappush(q, (heightMap[i][0], i, 0))
            vis[i][0] = True
            heapq.heappush(
                q, (heightMap[i][len(heightMap[0])-1], i, len(heightMap[0])-1))
            vis[i][len(heightMap[0])-1] = True
        for i in range(1,len(heightMap[0])-1):
            heapq.heappush(q, (heightMap[0][i], 0, i))
            vis[0][i] = True
            heapq.heappush(
                q, (heightMap[len(heightMap)-1][i], len(heightMap)-1, i))
            vis[len(heightMap)-1][i] = True

        s = 0
        while len(q) > 0:
            (value, x, y) = heapq.heappop(q)
            for d in dir:
                nxt = self.tuple_add((x, y), d)
                if self.inside(nxt, (0, 0), (len(heightMap), len(heightMap[0]))) and not vis[nxt[0]][nxt[1]]:
                    vis[nxt[0]][nxt[1]] = True
                    if heightMap[nxt[0]][nxt[1]] < value:
                        s += value-heightMap[nxt[0]][nxt[1]]
                        heapq.heappush(q, (value, nxt[0], nxt[1]))
                    else:
                        heapq.heappush(
                            q, (heightMap[nxt[0]][nxt[1]], nxt[0], nxt[1]))
        return s


if __name__ == '__main__':
