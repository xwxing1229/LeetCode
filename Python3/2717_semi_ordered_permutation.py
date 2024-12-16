# https://leetcode.cn/problems/semi-ordered-permutation/

class Solution:
    def semiOrderedPermutation(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        n = len(nums)
        min_idx, max_idx = 0, 0
        for i, val in enumerate(nums):
            if val == 1:
                min_idx = i
            elif val == n:
                max_idx = i
        
        res = min_idx + n - 1 - max_idx
        if min_idx > max_idx:
            res -= 1
        return res