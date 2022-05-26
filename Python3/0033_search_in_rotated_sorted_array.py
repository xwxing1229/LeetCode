# https://leetcode.cn/problems/search-in-rotated-sorted-array/

class Solution:
    def search(self, nums, target):
        """
        Inputs:
            nums: list[int]
            target: int
        Outputs:
            res: int
        """
        
        l = 0
        r = len(nums) - 1
        while l <= r:
            mid = (l + r) // 2 
            if target == nums[mid]:
                return mid

            # nums[l], nums[l+1], ..., nums[mid] is in the ascending order
            if nums[l] <= nums[mid]:
                if (nums[l] <= target) and (target <= nums[mid]):
                    r = mid - 1
                else:
                    l = mid + 1
            else:
                if (nums[mid] <= target) and (target <= nums[r]):
                    l = mid + 1
                else:
                    r = mid - 1
        return -1
