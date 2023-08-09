# https://leetcode.cn/problems/maximum-absolute-sum-of-any-subarray/

class Solution:
    def maxAbsoluteSum(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        res = abs(nums[0])
        dp_max, dp_min = nums[0], nums[0]
        for i in range(1, len(nums)):
            dp_max = max(dp_max + nums[i], nums[i])
            dp_min = min(dp_min + nums[i], nums[i])
            res = max(res, max(abs(dp_max), abs(dp_min)))
        return res