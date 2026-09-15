# https://leetcode.cn/problems/maximum-number-of-non-overlapping-palindrome-substrings/

class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        n = len(s)
        # dp[i]: number of palindromes in s[: i]
        dp = [0 for _ in range(n+1)]
        for i in range(k, n+1):
            dp[i] = dp[i-1] # s[i-1] not used
            if s[i-k: i] == s[i-k: i][::-1]:
                dp[i] = max(dp[i], dp[i-k]+1)
            if i > k and s[i-k-1: i] == s[i-k-1: i][::-1]:
                dp[i] = max(dp[i], dp[i-k-1]+1)
        return dp[n]