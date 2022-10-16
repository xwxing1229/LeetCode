# https://leetcode.cn/problems/partition-equal-subset-sum/

class Solution:
    def canPartition(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: bool
        """

        # dp[i][j] = True: it is possible to construct a sublist (can be empty) from
        # [nums[0], nums[1], ..., nums[i]] such that the sum of this sublist is j.

        s = sum(nums)
        if s % 2 != 0:
            return False
        tar = s // 2
        if max(nums) > tar:
            return False

        n = len(nums)
        dp = [[False for j in range(tar+1)] for i in range(n)]
        for i in range(n):
            dp[i][0] = True
            dp[i][nums[i]] = True

        for i in range(1, n):
            for j in range(1, tar+1):
                if j >= nums[i]:
                    dp[i][j] = dp[i-1][j-nums[i]] or dp[i-1][j]
                else:
                    dp[i][j] = dp[i-1][j]
        return dp[n-1][tar]

        # Space complexity can be easily optimized since dp[i] only depends on dp[i-1].