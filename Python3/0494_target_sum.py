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
        if s < target or (s - target) % 2 != 0:
            return 0

        neg = (s - target) // 2
        n = len(nums)
        dp = [0 for j in range(neg+1)]
        dp[0] = 1
        for i in range(1, n+1):
            num = nums[i-1]
            for j in range(neg, -1, -1):
                if j >= num:
                    dp[j] += dp[j-num]
        return dp[neg]
