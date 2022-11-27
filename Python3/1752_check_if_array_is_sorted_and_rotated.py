# https://leetcode.cn/problems/check-if-array-is-sorted-and-rotated/

class Solution:
    def check(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: bool
        """
        cut = -1
        for i in range(1, len(nums)):
            if nums[i] < nums[i-1]:
                if cut > 0:
                    return False
                cut = nums[0]
        if cut > 0 and nums[-1] > cut:
            return False
        else:
            return True
