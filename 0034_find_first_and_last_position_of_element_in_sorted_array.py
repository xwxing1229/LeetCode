# https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution:
    def searchRange(self, nums, target):
        """
        Inputs:
            nums: list[int]
            target: int
        Outputs:
            res: list[int]
        """

        if nums == []:
            return [-1, -1]

        l = self.find_first(nums, target)
        if l == -1:
            r = -1
        else:
            r = self.find_last(nums, target)

        res = [l, r]
        return res

    def find_first(self, nums, target):
        """
        Inputs:
            nums: list[int]
            target: int
        Outputs:
            res: int
        """

        # Find the first number that is greater than or equal to target.
        # Return its index.

        l = 0
        r = len(nums) - 1
        while l < r:
            mid = (l + r) // 2
            if nums[mid] < target:
                l = mid + 1
            else:
                r = mid

        # Check if this number is equal to target.
        if nums[l] != target:
            l = -1

        res = l
        return res

    def find_last(self, nums, target):
        """
        Inputs:
            nums: list[int]
            target: int
        Outputs:
            res: int
        """

        # Find the first number that is greater than target.
        # Return the index of the last number before this one.

        l = 0
        r = len(nums) - 1
        while l <= r:
            mid = (l + r) // 2
            if nums[mid] <= target:
                l = mid + 1
            else:
                r = mid - 1

        res = l - 1
        return res