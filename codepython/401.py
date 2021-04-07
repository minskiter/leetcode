from header import TreeNode
from typing import List, Set
from collections import OrderedDict, Counter
from queue import Queue, LifoQueue
from bisect import bisect_left
import heapq

class Solution:
    def readBinaryWatch(self, num: int) -> List[str]:
        ans = []
        for i in range(1<<10):
            j = i
            cnt = 0
            while j>0:
                j-=(j&-j)
                cnt+=1
            if cnt==num and (i>>6)<12 and (i&((1<<6)-1))<60:
                ans.append("{}:%02d".format(i>>6) % (i&((1<<6)-1)))
        return ans

            

if __name__=='__main__':
    pass