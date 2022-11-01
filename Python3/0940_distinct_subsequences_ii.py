# https://leetcode.cn/problems/distinct-subsequences-ii/

class Solution:
    def distinctSubseqII(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: int
        """

        # dp[i]: number of distinct subsequences that end with s[i]
        # last[i]: index in s of the last occurrence of the ith letter in "abc...xyz"
        n = len(s)
        dp = [1 for i in range(n)]
        last = [-1 for i in range(26)]
        for i in range(n):
            for idx in last:
                if idx != -1:
                    dp[i] = (dp[i] + dp[idx]) % 1000000007
            last[ord(s[i]) - ord("a")] = i
        
        res = 0
        for idx in last:
            if idx != -1:
                res = (res + dp[idx]) % 1000000007
        return res