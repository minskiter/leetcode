from typing import List
from random import randint

# 洗牌算法
class Solution:

    def __init__(self, nums: List[int]):
        self.nums = nums

    def reset(self) -> List[int]:
        """
        Resets the array to its original configuration and return it.
        """
        return self.nums

    def shuffle(self) -> List[int]:
        """
        Returns a random shuffling of the array.
        """
        random_list = list(self.nums)
        lens = len(random_list)-1
        cnts = randint(0, lens)
        for i in range(cnts):
            x = randint(0, lens)
            y = randint(0, lens)
            random_list[x], random_list[y] = random_list[y], random_list[x]
        return random_list
