from typing import List


class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        cnt: int = 0
        for by in data:
            bi = 1 << 7
            if cnt == 0:
                if (by & bi) == 0:
                    continue
                while bi > 0 and (by & bi) > 0:
                    cnt += 1
                    bi >>= 1
                if cnt == 1:
                    return False
                cnt -= 1
            else:
                cnt -= 1
                if (by & bi) == 0 or (by & (bi >> 1)) > 0:
                    return False
        return cnt==0


if __name__ == "__main__":
    print(Solution().validUtf8([255]))
