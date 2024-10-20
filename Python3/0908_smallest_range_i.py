# https://leetcode.cn/problems/smallest-range-i/

class Solution:
    def smallestRangeI(self, nums, k):
        """
        Inputs:
            nums: list[int]
            k: int
        Outputs:
            res: int
        """
        num_min, num_max = min(nums), max(nums)
        res = max(0, num_max - num_min - 2*k)
        return res