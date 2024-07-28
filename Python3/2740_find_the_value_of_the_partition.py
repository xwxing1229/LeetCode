# https://leetcode.cn/problems/find-the-value-of-the-partition/

class Solution:
    def findValueOfPartition(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        nums.sort()
        res = nums[1] - nums[0]
        for i in range(1, len(nums)):
            res = min(res, nums[i]-nums[i-1])
        return res