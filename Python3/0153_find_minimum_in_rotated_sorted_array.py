# https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/

class Solution:
    def findMin(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        left = 0
        right = len(nums) - 1
        while left < right:
            mid = left + (right - left) // 2
            val = nums[mid]

            if val <= nums[right]:
                right = mid
            else:
                left = mid + 1
        return nums[left]
