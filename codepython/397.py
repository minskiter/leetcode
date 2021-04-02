class Solution:
    def integerReplacement(self, n: int) -> int:
        if n == 1:
            return 1
        if n & 1:
            return min(self.integerReplacement(n-1), self.integerReplacement(n+1))+1
        return self.integerReplacement(n//2)+1
