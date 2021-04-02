class Solution:
    def lastRemaining(self, n: int) -> int:
        i = 2
        l = 1
        f = True
        while i <= n and l > 0 and l <= n:
            if not f:
                l -= i*(n//i)
                while l < 0:
                    l += i
                if l-(i >> 1) > 0:
                    l -= (i >> 1)
                else:
                    l += (i >> 1)
            else:
                l += i*(n//i)
                while l > n:
                    l -= i
                if l+(i >> 1) <= n:
                    l += (i >> 1)
                else:
                    l -= (i >> 1)
            f ^= True
            i *= 2
        return l


if __name__ == "__main__":
    for i in range(1,20):
        print("{}:{}".format(i,Solution().lastRemaining(i)))
