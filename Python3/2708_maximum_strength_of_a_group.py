# https://leetcode.cn/problems/maximum-strength-of-a-group/

class Solution:
    def maxStrength(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        min_, max_ = nums[0], nums[0]
        for num in nums[1:]:
            min_pre = min_
            min_ = min(min_, num, num*min_, num*max_)
            max_ = max(max_, num, num*min_pre, num*max_)
        return max_