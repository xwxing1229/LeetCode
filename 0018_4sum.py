# https://leetcode-cn.com/problems/4sum/

class Solution:
    def fourSum(self, nums, target):
        """
        Inputs:
            nums: list[int]
            target: int
        Outputs:
            res: list[list[int]]
        """
        
        res = []
        nums.sort()
        n = len(nums)
        for i in range(n):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            
            for j in range(i+1,n):
                if j > i + 1 and nums[j] == nums[j-1]:
                    continue
                
                left = j + 1
                right = n - 1
                while left < right:
                    sum_4 = nums[i] + nums[j] + nums[left] + nums[right]
                    if sum_4 == target:
                        res.append([nums[i], nums[j], nums[left], nums[right]])
                        left = left + 1
                        right = right - 1
                        
                        while left < right and nums[left] == nums[left-1]:
                            left = left + 1
                        while left < right and nums[right] == nums[right+1]:
                            right = right - 1
                            
                    elif sum_4 < target:
                        left = left + 1
                    else:
                        right = right - 1
        return res