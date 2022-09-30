# https://leetcode.cn/problems/combination-sum-iv/

class Solution:
    def combinationSum4(self, nums, target):
        """
        Inputs:
            nums: list[int]
            target: int
        Outputs:
            res: int
        """

        dp = [0 for _ in range(target+1)]
        dp[0] = 1
        for i in range(1, target+1):
            for num in nums:
                if num <= i:
                    dp[i] = dp[i] + dp[i-num]
        return dp[target]