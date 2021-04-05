from queue import Queue
from typing import List


class Solution:
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        choices = ['A', 'C', 'G', 'T']
        bank_set = set()
        for gene in bank:
            bank_set.add(gene)
        if end not in bank_set:
            return -1
        vis = set()
        q = Queue()
        q.put((0, start))
        vis.add(start)
        cnt=0
        while not q.empty():
            (step, head) = q.get()
            for i in range(len(head)):
                for j in choices:
                    choice = head[:i]+j+head[i+1:]
                    if choice in bank_set and choice not in vis:
                        if choice == end:
                            return step+1
                        q.put((step+1, choice))
                        vis.add(choice)
        return -1


if __name__ == '__main__':
    print(Solution().minMutation("AACCTTGG",
                                 "AATTCCGG",
                                 ["AATTCCGG", "AACCTGGG", "AACCCCGG", "AACCTACC"]))
