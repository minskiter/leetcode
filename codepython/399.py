from header import TreeNode
from typing import List, Set
from collections import OrderedDict, Counter
from queue import Queue, LifoQueue
from bisect import bisect_left
import heapq


class Graph:
    def __init__(self):
        self.graph = {}

    def addEdge(self, f, t, val):
        if f not in self.graph:
            self.graph = {}
        self.graph[f][t] = val

    def getEdge(self, f, t):
        if f not in self.graph:
            return None
        if t not in self.graph[f]:
            return None
        return self.graph[f][t]

    def getTo(self, f):
        if f not in self.graph:
            return []
        return self.graph[f].keys()

# Solution Here


class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        g: Graph = Graph()
        for index, eq in enumerate(equations):
            (f, t) = tuple(eq)
            val = values[index]
            g.addEdge(f,f,1.0)
            g.addEdge(t,t,1.0)
            side_f = g.getTo(f)
            side_t = g.getTo(t)
            for a in side_f:
                a_val = g.getEdge(f,a)
                for b in side_t:
                    b_val = g.getEdge(t,b)
                    g.addEdge(a,b,1/a_val*val*b_val)
                    g.addEdge(b,a,1/b_val/val*a_val)
        query_result: List[float] = []
        for q in queries:
            (f, t) = tuple(q)
            val = g.getEdge(f, t)
            if val == None:
                query_result.append(-1.0)
            else:
                query_result.append(val)
        return query_result


if __name__ == '__main__':
    pass
