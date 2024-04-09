# https://leetcode.cn/problems/maximum-count-of-positive-integer-and-negative-integer/

class Solution:
    def maximumCount(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        i = 0
        while i < len(nums) and nums[i] < 0:
            i += 1
        res = i
        while i < len(nums) and nums[i] == 0:
            i += 1
        res = max(res, len(nums)-i)
        return res