# https://leetcode.cn/problems/rotate-array/
        
class Solution:
    def rotate(self, nums, k):
        """
        Do not return anything, modify nums in-place instead.
        """

        """
        Inputs:
            nums: list[int]
            k: int
        """

        def reverse(left, right):
            while left < right:
                tmp = nums[left]
                nums[left] = nums[right]
                nums[right] = tmp

                left = left + 1
                right = right - 1

        n = len(nums)
        k = k % n
        reverse(0, n-1)
        reverse(k, n-1)
        reverse(0, k-1)