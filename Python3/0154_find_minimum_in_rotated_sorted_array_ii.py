# https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution:
    def findMin(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        return self.findMinSub(nums, 0, len(nums)-1)

    def findMinSub(self, nums, left, right):
        while left < right:
            mid = left + (right - left) // 2
            val = nums[mid]
            if val < nums[right]:
                right = mid
            elif val > nums[right]:
                left = mid + 1
            else:
                tmp1 = self.findMinSub(nums, left, mid-1)
                tmp2 = self.findMinSub(nums, mid+1, right)
                return min([tmp1, tmp2, val])
        return nums[left]
