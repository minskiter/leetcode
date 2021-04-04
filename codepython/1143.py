class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp = [[0]*(len(text2)+1) for i in range(len(text2)+1)]
        print(dp)
        for index1, ch1 in enumerate(text1):
            for index2, ch2 in enumerate(text2):
                if ch1 == ch2:
                    dp[index1+1][index2 +
                                 1] = max(dp[index1+1][index2+1], dp[index1][index2]+1)
                dp[index1+1][index2+1] = max(dp[index1+1][index2+1],
                                             max(dp[index1][index2+1], dp[index1+1][index2]))
        return dp[len(text1)][len(text2)]


if __name__ == "__main__":
    print(Solution.longestCommonSubsequence("", "abcba", "abcbcba"))
