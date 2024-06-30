# https://leetcode.cn/problems/target-sum/

class Solution:
    def findTargetSumWays(self, nums, target):
        """
        Inputs:
            nums: list[int]
            target: int
        Outputs:
            res: int
        """
        s = sum(nums)
        if s < target or s < -target:
            return 0
        # [-s, s] -> [0, 2s]
        dp = [[0 for _ in range(2*s+1)] for _ in range(len(nums))]
        dp[0][nums[0] + s] += 1
        dp[0][-nums[0] + s] += 1
        for i in range(1, len(nums)):
            num = nums[i]
            for sum_pre, v in enumerate(dp[i-1]):
                if v > 0:
                    dp[i][num + sum_pre] += v
                    dp[i][-num + sum_pre] += v
        return dp[-1][target + s]
