# https://leetcode.cn/problems/predict-the-winner/

class Solution:
    def predictTheWinner(self, nums: list[int]) -> bool:
        n = len(nums)
        dp = [[0 for _ in range(n)] for _ in range(n)]
        for i in range(n-1, -1, -1):
            dp[i][i] = nums[i]
            for j in range(i+1, n):
                dp[i][j] = max(nums[i] - dp[i+1][j],
                               nums[j] - dp[i][j-1])
        return dp[0][-1] >= 0