# https://leetcode-cn.com/problems/jump-game/

class Solution:
    def canJump(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: bool
        """
        
        n = len(nums)
        max_jump = 0
        for i in range(n):
            if i <= max_jump and i + nums[i] > max_jump:
                max_jump = i + nums[i]
        
        if max_jump >= n - 1:
            return True
        else:
            return False