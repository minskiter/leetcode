from typing import List, Dict
from random import randint


class Solution:

    def __init__(self, nums: List[int]):
        self.indexes: Dict[List[int]] = {}
        for i, num in enumerate(nums):
            if num not in self.indexes:
                self.indexes = [i]
            else:
                self.indexes.append(i)

    def pick(self, target: int) -> int:
        return self.indexes[target][randint(0, len(self.indexes[target]-1))]

