# https://leetcode.cn/problems/rotate-function/

class Solution:
    def maxRotateFunction(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        sum_nums = sum(nums)
        f = 0
        n = len(nums)
        for i in range(1, n):
            f = f + i * nums[i]
        res = f
        for i in range(n-1, 0, -1):
            f = f + sum_nums - n * nums[i]
            res = max(res, f)
        return res

