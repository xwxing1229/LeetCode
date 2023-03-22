# https://leetcode.cn/problems/best-team-with-no-conflicts/

class Solution:
    def bestTeamScore(self, scores, ages):
        """
        Inputs:
            scores, ages: list[int]
        Outputs:
            res: int
        """
        pairs = sorted(zip(scores, ages), key=lambda x: (x[0], x[1]))
        n = len(scores)
        dp = [0 for i in range(n)]
        res = pairs[0][0]
        for i in range(n):
            score, age = pairs[i]
            for j in range(i):
                if age >= pairs[j][1]:
                    dp[i] = max(dp[j], dp[i])
            dp[i] += score
            res = max(res, dp[i])
        return res
