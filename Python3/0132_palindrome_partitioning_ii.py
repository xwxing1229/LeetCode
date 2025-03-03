# https://leetcode.cn/problems/palindrome-partitioning-ii/

class Solution:
    def minCut(self, s: str) -> int:
        # dp[j]: minimum cuts needed for a palindrome partitioning of s[:j+1].
        # dp[j] = min_i dp[i] + 1, for i = 0, ..., j-1 and s[i+1:j+1] is a palindrome.

        n = len(s)
        palindrome = [[True for _ in range(n)] for _ in range(n)]
        for j in range(1, n):
            for i in range(j-1, -1, -1):
                palindrome[i][j] = (s[i] == s[j] and palindrome[i+1][j-1])
        
        dp = [0 for _ in range(n)]
        for j in range(n):
            if palindrome[0][j]:
                continue
            tmp = n - 1
            for i in range(j):
                if palindrome[i+1][j]:
                    tmp = min(tmp, dp[i]+1)
            dp[j] = tmp
        return dp[-1]