# https://leetcode.cn/problems/greatest-sum-divisible-by-three/

class Solution:
    def maxSumDivThree(self, nums: list[int]) -> int:
        # dp[i][j]: maximum sum of elements chosen from nums[0], ..., nums[i-1]
        #           with sum % 3 = j.
        dp = [[0, -1, -1] for i in range(len(nums)+1)]
        for i, num in enumerate(nums):
            rem = num % 3
            for j in range(3):
                match = (3 + j - rem) % 3
                if dp[i][match] >= 0:
                    dp[i+1][j] = max(dp[i][j], dp[i][match]+num)
                else:
                    dp[i+1][j] = dp[i][j]
        return dp[-1][0]