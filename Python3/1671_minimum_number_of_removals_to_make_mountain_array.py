# https://leetcode.cn/problems/minimum-number-of-removals-to-make-mountain-array/

class Solution:
    def minimumMountainRemovals(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        prefix = self.getLongestIncreasingSubsequence(nums)
        suffix = self.getLongestIncreasingSubsequence(nums[::-1])[::-1]

        length = 0
        for pre, suf in zip(prefix, suffix):
            if pre > 1 and suf > 1:
                length = max(length, pre+suf-1)
        return len(nums) - length

    def getLongestIncreasingSubsequence(self, nums):
        n = len(nums)
        dp = [1 for _ in range(n)]
        for i in range(n):
            for j in range(i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], dp[j]+1)
        return dp