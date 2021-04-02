class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i = iter(s)
        si = next(i)
        for ch in t:
            if si == ch:
                si = next(i)
        return next(si, None) == None


if __name__ == "__main__":
    # it = iter([1,2])
    # print(next(it))
