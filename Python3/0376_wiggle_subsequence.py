# https://leetcode.cn/problems/wiggle-subsequence/

class Solution:
    def wiggleMaxLength(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        
        res = 1
        diff_pre = 0
        for i in range(1, len(nums)):
            diff = nums[i] - nums[i-1]
            if diff > 0:
                diff = 1
                if diff - diff_pre != 0:
                    res = res + 1
                diff_pre = 1
            elif diff < 0:
                diff = -1
                if diff - diff_pre != 0:
                    res = res + 1
                diff_pre = -1
        return res
