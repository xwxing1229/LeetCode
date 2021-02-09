# https://leetcode-cn.com/problems/house-robber/submissions/

class Solution:
    def rob(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        # Simple dynamic programming.
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]

        dp = [0 for i in range(n+1)]
        dp[0] = nums[0]
        for i in range(1,n):
            dp[i] = max(dp[i-1], dp[i-2] + nums[i])

        res = dp[n-1]
        return res