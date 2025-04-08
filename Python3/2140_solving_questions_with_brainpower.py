# https://leetcode.cn/problems/solving-questions-with-brainpower/

class Solution:
    def mostPoints(self, questions):
        """
        Inputs:
            questions: list[list[int]]
        Outputs:
            res: int
        """
        n = len(questions)
        dp = [0 for _ in range(n+1)]
        for i in range(n-1, -1, -1):
            j = i + questions[i][1] + 1
            if j > n:
                j = n
            dp[i] = max(dp[i+1], questions[i][0]+dp[j])
        return dp[0]