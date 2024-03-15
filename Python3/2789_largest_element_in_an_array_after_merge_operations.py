# https://leetcode.cn/problems/largest-element-in-an-array-after-merge-operations/

class Solution:
    def maxArrayValue(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        res = nums[-1]
        for i in range(len(nums)-2, -1, -1):
            if nums[i] <= res:
                res += nums[i]
            else:
                res = nums[i]
        return res