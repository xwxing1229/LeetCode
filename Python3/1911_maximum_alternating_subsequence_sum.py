# https://leetcode.cn/problems/maximum-alternating-subsequence-sum/

class Solution:
    def maxAlternatingSum(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        # dp[i][0]: maximum alternating sum until the ith element with the size
        #           of the corresponding subsequence even
        # dp[i][1]: maximum alternating sum until the ith element with the size
        #           of the corresponding subsequence odd
        n = len(nums)
        dp = [[0,0] for _ in range(n)]
        dp[0][1] = nums[0]
        for i in range(1, n):
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - nums[i])
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + nums[i])
        return max(dp[n-1][0], dp[n-1][1])