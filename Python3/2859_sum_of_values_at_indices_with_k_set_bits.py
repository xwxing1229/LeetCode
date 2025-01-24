# https://leetcode.cn/problems/sum-of-values-at-indices-with-k-set-bits/

class Solution:
    def sumIndicesWithKSetBits(self, nums, k):
        """
        Inputs:
            nums: list[int]
            k: int
        Outputs:
            res: int
        """
        res = 0
        for i, num in enumerate(nums):
            idx = i
            ones = 0
            while idx > 0:
                if (idx & 1) == 1:
                    ones += 1
                idx = (idx >> 1)
            if ones == k:
                res += num
        return res