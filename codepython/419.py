from header import TreeNode
from typing import List, Set, Tuple
from collections import OrderedDict, Counter
from queue import Queue, LifoQueue
from bisect import bisect_left
import heapq


class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        cnt = 0
        for row in range(board):
            for col in range(board[0]):
                if board[row][col]=='X':
                    if not ((row>0 and board[row-1][col]=='X') or (col>0 and board[row][col-1])):
                        cnt+=1
        return cnt


if __name__ == '__main__':
    pass
