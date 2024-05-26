# https://leetcode.cn/problems/find-the-most-competitive-subsequence/

class Solution:
    def mostCompetitive(self, nums, k):
        """
        Inputs:
            nums: list[int]
            k: int
        Outputs:
            res: list[int]
        """
        res = []
        n = len(nums)
        for i, num in enumerate(nums):
            while len(res) > 0 and num < res[-1] and len(res) + n - i > k:
                res.pop()
            res.append(num)
        return res[:k]