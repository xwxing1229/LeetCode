# https://leetcode.cn/problems/find-peak-element/

class Solution:
    def findPeakElement(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        n = len(nums)
        left = 0
        right = n - 1
        while left <= right:
            mid = left + (right - left) // 2
            val_left = nums[max(0, mid-1)]
            val_mid = nums[mid]
            val_right = nums[min(n-1, mid+1)]
            if (val_left <= val_mid) and (val_mid >= val_right):
                return mid

            if val_mid <= val_right:
                left = mid + 1
            else:
                right = mid - 1
        return -1
