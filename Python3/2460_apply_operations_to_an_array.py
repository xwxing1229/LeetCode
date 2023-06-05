# https://leetcode.cn/problems/apply-operations-to-an-array/

class Solution:
    def applyOperations(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[int]
        """
        n = len(nums)
        for i in range(n-1):
            if nums[i] == nums[i+1]:
                nums[i] = nums[i] * 2
                nums[i+1] = 0
        j = 0
        for i in range(n):
            while j < n and nums[j] != 0:
                j += 1
            if nums[i] != 0 and i > j:
                nums[j] = nums[i]
                nums[i] = 0
                j += 1
        return nums