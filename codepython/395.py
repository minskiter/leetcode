class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        for ch in set(s):
            if s.count(ch)<k:
                return max(self.longestSubstring(sub,k) for sub in s.split(ch))
        return len(s)
        
