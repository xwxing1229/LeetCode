# https://leetcode.cn/problems/find-closest-number-to-zero/

class Solution:
    def findClosestNumber(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        res, d_min = nums[0], abs(nums[0])
        for num in nums:
            d = abs(num)
            if d < d_min or (d == d_min and num > res):
                res = num
                d_min = d
        return res