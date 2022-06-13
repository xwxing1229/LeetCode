# https://leetcode.cn/problems/search-in-rotated-sorted-array-ii/

class Solution:
    def search(self, nums, target):
        """
        Inputs:
            nums: list[int]
            target: int
        Outputs:
            res: bool
        """

        left = 0
        right = len(nums) - 1
        while left <= right:
            print(left, right)
            mid = left + (right - left) // 2
            val = nums[mid]

            if target == val:
                return True

            if nums[left] < val:
                if (nums[left] <= target) and (target < val):
                    right = mid - 1
                else:
                    left = mid + 1
            elif val < nums[right]:
                if (val < target) and (target <= nums[right]):
                    left = mid + 1
                else:
                    right = mid - 1
            else:
                if target == nums[left]:
                    return True
                left = left + 1
        return False
