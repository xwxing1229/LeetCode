# https://leetcode.cn/problems/global-and-local-inversions/

class Solution:
    def isIdealPermutation(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: bool
        """
        for i, num in enumerate(nums):
            if num - i < -1 or num - i > 1:
                return False
        return True

        # Another method:
        # nums[i] < min(nums[i+2], nums[i+3], ..., nums[n-1]), so just
        # scan nums in the reverse direction and maintain a minimum value.