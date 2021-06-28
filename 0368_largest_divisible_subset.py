# https://leetcode-cn.com/problems/largest-divisible-subset/

class Solution:
    def largestDivisibleSubset(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[int]
        """

        nums.sort()
        n = len(nums)
        # dp[i] indicates the maximum length of the subset that satisfies
        # the requirement and contains nums[i] as its largest element.
        dp = [1 for i in range(n)]
        for i in range(1, n):
            for j in range(i):
                if nums[i] % nums[j] == 0:
                    dp[i] = max(dp[j]+1, dp[i])

        max_len = max(dp)
        max_idx = dp.index(max_len)
        res = [nums[max_idx]]
        max_len = max_len - 1
        while max_len > 0:
            for i in range(max_idx):
                if dp[i] == max_len and nums[max_idx] % nums[i] == 0:
                    res.append(nums[i])
                    max_len = max_len - 1
                    max_idx = i
                    break

        return res