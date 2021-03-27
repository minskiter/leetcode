import random


class RandomizedSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._set = {}
        self._list = []

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        """
        if val in self._set:
            return False
        self._set[val] = len(self._list)
        self._list.append(val)
        return True

    def remove(self, val: int) -> bool:
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        """
        if val not in self._set:
            return False
        self._list[self._set[val]] = self._list[-1]
        self._list.pop()
        self._set.pop(val)
        return True

    def getRandom(self) -> int:
        """
        Get 
        """
        return self._list[random.randint(0, len(self._list)-1)]
