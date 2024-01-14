# https://leetcode.cn/problems/collecting-chocolates/

class Solution:
    def minCost(self, nums, x):
        """
        Inputs:
            nums: list[int]
            x: int
        Outputs:
            res: int
        """
        res = sum(nums)
        mins = [num for num in nums]
        n = len(nums)
        for i in range(1, n):
            for j in range(n):
                mins[j] = min(mins[j], nums[(j+n-i)%n])
            res = min(res, sum(mins)+i*x)
        return res