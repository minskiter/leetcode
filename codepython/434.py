from typing import List, Set
from queue import Queue, LifoQueue
import headq

# Solution Here


class Solution:
    def countSegments(self, s: str) -> int:
        s.strip()
        cnt = 0
        pre = '$'
        for ch in s:
            if ch == ' ':
                if pre != ' ' and pre != '$':
                    cnt += 1
            elif pre == '$':
                cnt += 1
            pre = ch
        return cnt


if __name__ == '__main__':
    pass
