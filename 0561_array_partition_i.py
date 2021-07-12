# https://leetcode-cn.com/problems/array-partition-i/
class Solution:
    def arrayPairSum(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        nums.sort()
        n = len(nums)
        res = 0
        for i in range(n//2):
            res = res + nums[i*2]
        return res