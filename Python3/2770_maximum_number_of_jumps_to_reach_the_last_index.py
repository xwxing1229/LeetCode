# https://leetcode.cn/problems/maximum-number-of-jumps-to-reach-the-last-index/

class Solution:
    def maximumJumps(self, nums: list[int], target: int) -> int:
        n = len(nums)
        dp = [-1 for _ in range(n)]
        dp[0] = 0
        for i in range(1, n):
            for j in range(i):
                diff = nums[i] - nums[j]
                if -target <= diff <= target and dp[j] >= 0 and dp[i] < dp[j] + 1:
                    dp[i] = dp[j]+1
        return dp[-1]