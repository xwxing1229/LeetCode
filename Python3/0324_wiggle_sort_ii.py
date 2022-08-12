# https://leetcode.cn/problems/wiggle-sort-ii/

class Solution:
    def wiggleSort(self, nums):
        """
        Do not return anything, modify nums in-place instead.
        """
        """
        Inputs:
            nums: list[int]
        Outputs:
            None
        """
        n = len(nums)
        nums_sort = sorted(nums, reverse=True)
        k = 0
        for i in range(1, n, 2):
            nums[i] = nums_sort[k]
            k = k + 1
        for i in range(0, n, 2):
            nums[i] = nums_sort[k]
            k = k + 1