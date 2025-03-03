# https://leetcode.cn/problems/palindrome-partitioning-iii/

class Solution:
    def palindromePartition(self, s: str, k: int) -> int:
        # dp[x][j]: minimal number of characters that we need to change to partition
        # s[:j+1] into x+1 palindromes (j >= x).
        # dp[x][j] = min_i dp[x-1][i] + change[i+1][j], i = x-1, ..., j-1.

        n = len(s)
        change = [[0 for _ in range(n)] for _ in range(n)]
        for j in range(1, n):
            for i in range(j-1, -1, -1):
                change[i][j] = change[i+1][j-1] + (s[i] != s[j])
        
        dp = [[change[0][j] for j in range(n)] for _ in range(k)]
        for x in range(1, k):
            for j in range(x, n):
                tmp = n
                for i in range(x-1, j):
                    tmp = min(tmp, dp[x-1][i]+change[i+1][j])
                dp[x][j] = tmp
        return dp[-1][-1]