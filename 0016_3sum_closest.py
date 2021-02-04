# https://leetcode-cn.com/problems/3sum-closest/

class Solution:
    def threeSumClosest(self, nums, target):
        """
        Inputs:
            nums: list[int]
            target: int
        Outputs:
            res: int
        """
        
        nums.sort()
        res = nums[0] + nums[1] + nums[2]
        n = len(nums)
        for i in range(n):
            left = i + 1
            right = n - 1
            while left < right:
                tmp = nums[i] + nums[left] + nums[right]
                diff = tmp - target
                if abs(diff) < abs(res-target):
                    res = tmp
                
                if diff == 0:
                    break
                elif diff < 0:
                    left = left + 1
                else:
                    right = right - 1
        return res