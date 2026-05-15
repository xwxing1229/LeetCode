# https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/

class Solution:
    def findMin(self, nums: list[int]) -> int:
        res = nums[0]
        left, right = 0, len(nums)-1
        while left <= right:
            mid = (left + right) // 2
            res = nums[mid]
            if nums[mid] < nums[right]:
                right = mid
            else:
                left = mid + 1
        return res