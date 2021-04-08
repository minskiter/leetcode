class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        s = []
        rm = 0
        for digit in num:
            while rm < k and len(s) > 0 and s[-1] > digit:
                s.pop()
                rm += 1
            s.append(digit)
        return "".join(s)


if __name__ == "__main__":
    print(Solution().removeKdigits("1432219",3))
