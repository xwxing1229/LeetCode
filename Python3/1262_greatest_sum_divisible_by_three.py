# https://leetcode.cn/problems/greatest-sum-divisible-by-three/

class Solution:
    def maxSumDivThree(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        # dp[i][j]: maximum sum of elements chosen from nums[0], ..., nums[i-1] with
        #           sum % 3 = j.
        dp = [[0, -1, -1] for i in range(len(nums)+1)]
        for i, num in enumerate(nums):
            for j in range(3):
                k = (3 + j - num%3) % 3
                if dp[i][k] >= 0:
                    dp[i+1][j] = max(dp[i][j], dp[i][k]+num)
                else:
                    dp[i+1][j] = dp[i][j]
        return dp[len(nums)][0]