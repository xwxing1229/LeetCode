# https://leetcode.cn/problems/maximum-ascending-subarray-sum/

class Solution:
    def maxAscendingSum(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        res, pre = nums[0], nums[0]
        for i in range(1, len(nums)):
            if nums[i] > nums[i-1]:
                pre = pre + nums[i]
            else:
                pre = nums[i]
            if pre > res:
                res = pre
        return res