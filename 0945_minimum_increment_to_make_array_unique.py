# https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique/

class Solution:
    def minIncrementForUnique(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        
        nums.sort()
        res = 0
        for i in range(1, len(nums)):
            if nums[i] <= nums[i-1]:
                tmp = nums[i]
                nums[i] = nums[i-1] + 1
                res = res + nums[i] - tmp
        return res