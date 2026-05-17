# https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution:
    def findMin(self, nums: list[int]) -> int:
        left, right = 0, len(nums)-1
        while left < right:
            mid = (left + right) // 2
            if nums[mid] > nums[right]:
                left = mid + 1
            elif nums[mid] < nums[right]:
                right = mid
            else:
                right -= 1
        return nums[left]