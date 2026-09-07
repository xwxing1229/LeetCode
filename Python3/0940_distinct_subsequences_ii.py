# https://leetcode.cn/problems/distinct-subsequences-ii/

class Solution:
    def distinctSubseqII(self, s: str) -> int:
        # dp[ch]: number of distinct subsequences that end with ch,
        # where ch = "a", "b", ..., "z".
        mod = int(1e9) + 7
        dp = [0 for _ in range(26)]
        total = 0
        for ch in s:
            idx = ord(ch) - ord("a")
            others = (total - dp[idx] + mod) % mod
            dp[idx] = 1 + total
            total = (others + dp[idx]) % mod
        return total