# https://leetcode-cn.com/problems/3sum/

class Solution:
    def threeSum(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[list[int]]
        """
        
        n = len(nums)
        if n < 3:
            return []
        
        res = []
        nums.sort()
        for i in range(n):
            if nums[i] > 0:
                break
            
            if i > 0 and nums[i] == nums[i-1]:
                continue
            
            left = i + 1
            right = n - 1
            while left < right:
                sum_3 = nums[i] + nums[left] + nums[right]
                if sum_3 == 0:
                    res.append([nums[i], nums[left], nums[right]])
                    while left < right and nums[left] == nums[left+1]:
                        left = left + 1
                    while left < right and nums[right] == nums[right-1]:
                        right = right - 1
                    left = left + 1
                    right = right - 1
                elif sum_3 > 0:
                    right = right - 1
                else:
                    left = left + 1
            return res