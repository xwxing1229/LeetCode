# https://leetcode.cn/problems/move-zeroes/

class Solution:
    def moveZeroes(self, nums):
        """
        Do not return anything, modify nums in-place instead.
        """

        """
        Inputs:
            nums: list[int]
        Outputs:
            None
        """
        idx_0 = 0
        idx = 0
        n = len(nums)
        while idx < n:
            while (idx_0 < n) and (nums[idx_0] != 0):
                idx_0 = idx_0 + 1

            idx = idx_0 + 1
            while (idx < n) and (nums[idx] == 0):
                idx = idx + 1

            if (idx_0 == n) or (idx == n):
                break

            nums[idx_0] = nums[idx]
            nums[idx] = 0