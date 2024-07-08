# https://leetcode.cn/problems/find-pivot-index/

class Solution:
    def pivotIndex(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        s = sum(nums)
        s_left = 0
        for i, num in enumerate(nums):
            if s_left == s-s_left-num:
                return i
            s_left += num
        return -1