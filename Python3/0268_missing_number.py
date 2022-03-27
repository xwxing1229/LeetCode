# https://leetcode-cn.com/problems/missing-number/

class Solution:
    def missingNumber(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        n = len(nums)
        sum_n = n * (n+1) // 2

        res = sum_n - sum(nums)
        return res