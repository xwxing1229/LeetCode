# https://leetcode-cn.com/problems/single-number/

class Solution:
    def singleNumber(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        
        '''
        new = sorted(nums)
        res = new[-1]
        i = 0
        while i < len(new)-1:
            if new[i] != new[i+1]:
                res = new[i]
                break
            else:
                i = i + 2
        return res
        '''
        
        # Property of XOR:
        # 1. a ^ 0 = a.
        # 2. a ^ a = 0.
        # 3. a ^ b ^ a = a ^ a ^ b = 0 ^ b = b.
        res = nums[0]
        for i in range(1,len(nums)):
            res = res ^ nums[i]
        return res