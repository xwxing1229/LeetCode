# https://leetcode.cn/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/

class Solution:
    def minOperations(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        res = 0
        for i in range(len(nums)-2):
            if nums[i] == 0:
                nums[i+1] ^= 1
                nums[i+2] ^= 1
                res += 1
        if nums[-1] == 1 and nums[-2] == 1:
            return res
        else:
            return -1