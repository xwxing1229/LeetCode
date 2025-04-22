# https://leetcode.cn/problems/count-number-of-bad-pairs/

from collections import defaultdict

class Solution:
    def countBadPairs(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        cnts = defaultdict(int)
        for i, num in enumerate(nums):
            cnts[num - i] += 1
        
        res = 0
        n = len(nums)
        for v in cnts.values():
            res += v * (n - v)
        return res // 2