# https://leetcode.cn/problems/minimum-operations-to-exceed-threshold-value-i/

class Solution:
    def minOperations(self, nums, k):
        """
        Inputs:
            nums: list[int]
            k: int
        Outputs:
            res: int
        """
        res = 0
        for num in nums:
            if num < k:
                res += 1
        return res