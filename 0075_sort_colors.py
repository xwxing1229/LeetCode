# https://leetcode-cn.com/problems/sort-colors/

class Solution:
    def sortColors(self, nums):
        """
        Inputs:
            nums: list[int]

        Do not return anything, modify nums in-place instead.
        """

        n = len(nums)
        idx = 0

        # Move 0s to the front of the list.
        for i in range(n):
            if nums[i] == 0:
                nums[i] = nums[idx]
                nums[idx] = 0
                idx = idx + 1

        # Move 1s to the middle part right after 0s.
        for i in range(idx, n):
            if nums[i] == 1:
                nums[i] = nums[idx]
                nums[idx] = 1
                idx = idx + 1