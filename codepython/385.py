from typing import List


class NestedInteger:
    def __init__(self, value=None):
        """
        If value is not specified, initializes an empty list.
        Otherwise initializes a single integer equal to value.
        """
        pass

    def isInteger(self):
        """
        @return True if this NestedInteger holds a single integer, rather than a nested list.
        :rtype bool
        """
        pass

    def add(self, elem):
        """
        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
        :rtype void
        """
        pass

    def setInteger(self, value):
        """
        Set this NestedInteger to hold a single integer equal to value.
        :rtype void
        """
        pass

    def getInteger(self):
        """
        @return the single integer that this NestedInteger holds, if it holds a single integer
        Return None if this NestedInteger holds a nested list
        :rtype int
        """
        pass

    def getList(self):
        """
        @return the nested list that this NestedInteger holds, if it holds a nested list
        Return None if this NestedInteger holds a single integer
        :rtype List[NestedInteger]
        """
        pass


class Solution:
    def deserialize(self, s: str) -> NestedInteger:
        stack = []
        have_num = False
        num = 0
        f = 1
        for index, ch in enumerate(s):
            if ch == '[':
                tmp = NestedInteger()
                if len(stack) != 0:
                    stack[-1].add(tmp)
                stack.append(tmp)
            elif str.isdigit(ch) or ch == '-':
                if ch == '-':
                    f = -1
                else:
                    have_num = True
                    num = num*10+int(ch)
            elif ch == ',':
                if have_num:
                    stack[-1].add(NestedInteger(f*num))
                    have_num = False
                    f = 1
                    num = 0
            elif ch == ']':
                if have_num:
                    stack[-1].add(NestedInteger(f*num))
                    have_num = False
                    f = 1
                    num = 0
                if len(stack) == 1:
                    return stack[-1]
                stack.pop()
        if have_num:
            return NestedInteger(f*num)
        return None
