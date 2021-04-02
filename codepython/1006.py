class Solution:
    def clumsy(self, N: int) -> int:
        ans: int = 0
        for i in range(N, 0, -4):
            f = 1
            if i != N:
                f = -1
            pans = i
            if i > 1:
                pans *= i-1
            if i > 2:
                pans //= i-2
            pans = f * pans
            if i > 3:
                pans += i-3
            ans += pans
        return ans

if __name__ == "__main__":
    print(Solution().clumsy(10000))
