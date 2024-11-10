# https://leetcode.cn/problems/single-element-in-a-sorted-array/

class Solution:
    def singleNonDuplicate(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        n = len(nums)
        res = nums[-1]
        left, right = 0, n//2-1
        while left <= right:
            mid = left + (right - left) // 2
            idx = 2 * mid
            if nums[idx] == nums[idx+1]:
                left = mid + 1
            else:
                right = mid - 1
                res = nums[idx]
        return res