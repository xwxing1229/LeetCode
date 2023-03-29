# https://leetcode.cn/problems/count-sorted-vowel-strings/

class Solution:
    def countVowelStrings(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: int
        """
        # dp[i][j]: number of valid strings of length i that end with the jth vowel
        # dp[i][0] = 1
        # dp[i][j] = dp[i-1][0] + dp[i-1][1] + ... + dp[i-1][j-1] + dp[i-1][j]
        dp = [1 for j in range(5)]
        for i in range(n-1):
            tmp = dp[0]
            for j in range(1, 5):
                tmp += dp[j]
                dp[j] = tmp
        return sum(dp)