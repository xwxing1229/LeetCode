# https://leetcode-cn.com/problems/largest-number-at-least-twice-of-others/

class Solution:
    def dominantIndex(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        
        if len(nums) == 1:
            return 0
        
        max_num = max(nums)
        idx = nums.index(max_num)
        
        nums.remove(max_num)
        second_max_num = max(nums)
        
        if max_num >= 2 * second_max_num:
            return idx
        else:
            return -1