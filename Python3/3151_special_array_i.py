# https://leetcode.cn/problems/special-array-i/

class Solution:
    def isArraySpecial(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: bool
        """
        pre = nums[0] % 2
        for i in range(1, len(nums)):
            cur = nums[i] % 2
            if pre + cur != 1:
                return False
            pre = cur
        return True