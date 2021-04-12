from header import TreeNode
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
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        vis = [[False]*len(heights[0]) for i in range(len(heights))]
        rev_vis = [[False]*len(heights[0]) for i in range(len(heights))]
        q = Queue()
        for i in range(len(heights[0])):
            q.put((0, i))
            vis[0][i] = True
        for i in range(1, len(heights)):
            q.put((i, 0))
            vis[i][0] = True
        dir = [(0, 1), (1, 0), (-1, 0), (0, -1)]
        while not q.empty():
            pos = q.get()
            for d in dir:
                nxt = pos+d
                if inside(nxt, (0, 0), (len(heights), len(heights[0]))) and not vis[nxt[0]][nxt[1]] and heights[nxt[0]][nxt[1]] >= heights[pos[0]][pos[1]]:
                    q.put(nxt)
                    vis[nxt[0]][nxt[1]] = True
        ans = []
        for i in range(len(heights[0])):
            if vis[len(heights)-1][i]:
                ans.append([len(heights)-1, i])
            rev_vis[len(heights)-1][i] = True
            q.put((len(heights)-1, i))
        for i in range(len(heights)-1):
            if vis[i][len(heights[0])-1]:
                ans.append([i][len(heights[0])-1])
            rev_vis[i][len(heights[0])-1] = True
            q.put((i, len(heights[0])-1))
        while not q.empty():
            pos = q.get()
            for d in dir:
                nxt = pos + d
                if inside(nxt, (0, 0), (len(heights), len(heights[0]))) and not rev_vis[nxt[0]][nxt[1]] and heights[nxt[0]][nxt[1]] >= heights[pos[0]][pos[1]]:
                    q.put(nxt)
                    rev_vis[nxt[0]][nxt[1]] = True
                    if vis[nxt[0]][nxt[1]]:
                        ans.append(list(nxt))
        return ans


if __name__ == '__main__':
    pass
