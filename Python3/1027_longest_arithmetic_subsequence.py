# https://leetcode.cn/problems/longest-arithmetic-subsequence/

class Solution:
    def longestArithSeqLength(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        n = len(nums)
        dp = [[1 for _ in range(1001)] for _ in range(n)]
        res = 0
        for i in range(1, n):
            for j in range(i):
                diff = nums[i] - nums[j] + 500
                dp[i][diff] = dp[j][diff] + 1
                if res < dp[i][diff]:
                    res = dp[i][diff]
        return res