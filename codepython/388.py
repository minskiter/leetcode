from typing import List


class Solution:
    def lengthLongestPath(self, input: str) -> int:
        paths: List[str] = input.split('\n')
        path_lens: List[int] = []
        max_length = 0
        length = 0
        for path in paths:
            level = 0
            for ch in path:
                if ch == '\t':
                    level += 1
                else:
                    break
            while level < len(path_lens):
                length -= path_lens[-1]
                path_lens.pop()
            if '.' in path:
                max_length = max(max_length,length+len(path))
            else:
                path_lens.append(len(path)-level)
        return max_length
            
            