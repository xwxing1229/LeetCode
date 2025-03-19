# https://leetcode.cn/problems/sum-of-beauty-in-the-array/

class Solution:
    def sumOfBeauties(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        n = len(nums)
        minright = [nums[-1] for _ in range(n)]
        for i in range(n-2, -1, -1):
            minright[i] = min(minright[i+1], nums[i+1])
        
        res, maxleft = 0, nums[0]
        for i in range(1, n-1):
            if nums[i] > maxleft and nums[i] < minright[i]:
                res += 2
            elif nums[i] > nums[i-1] and nums[i] < nums[i+1]:
                res += 1
            
            if nums[i] > maxleft:
                maxleft = nums[i]
                
        return res