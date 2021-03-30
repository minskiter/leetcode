class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        diff = 0
        for ch in s:
            diff ^=ord(ch)^ord(ch)
        for ch in t:
            diff ^=ord(ch)^ord(ch)
        return chr(diff)
