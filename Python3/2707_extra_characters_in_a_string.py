# https://leetcode.cn/problems/extra-characters-in-a-string/

class Solution:
    def minExtraChar(self, s, dictionary):
        """
        Inputs:
            s: str
            dictionary: list[str]
        Outputs:
            res: int
        """
        n = len(s)
        dp = [n for _ in range(n+1)]
        dp[0] = 0
        words = set(dictionary)
        for i in range(1, n+1):
            dp[i] = dp[i-1] + 1
            for j in range(i-1, -1, -1):
                if s[j:i] in words:
                    dp[i] = min(dp[i], dp[j])
        return dp[n]