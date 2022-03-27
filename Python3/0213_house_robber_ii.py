# https://leetcode-cn.com/problems/house-robber-ii/

class Solution:
    def rob(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        n = len(nums)
        if n == 1:
            return nums[0]
        if n == 2:
            return max(nums[0], nums[1])

        # Two conditions:
        # 1. The first house is included.
        # 2. The first house is not included.
        # These two conditions are handled separately using
        # dynamic programming.
        tmp1 = self.sub_max(nums[:n-1])
        tmp2 = self.sub_max(nums[1:])
        res = max(tmp1, tmp2)
        return res

    def sub_max(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        # Simple dynamic programming.
        n = len(nums)
        dp = [0 for _ in range(n+1)]
        dp[0] = nums[0]
        for i in range(n):
            dp[i] = max(dp[i-1], dp[i-2] + nums[i])

        res = max(dp)
        return res