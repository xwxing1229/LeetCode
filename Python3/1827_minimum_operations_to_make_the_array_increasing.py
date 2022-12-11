# https://leetcode.cn/problems/minimum-operations-to-make-the-array-increasing/

class Solution:
    def minOperations(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        res, pre = 0, nums[0]
        for i in range(1, len(nums)):
            if nums[i] <= pre:
                pre += 1
                res += (pre - nums[i])
            else:
                pre = nums[i]
        return res