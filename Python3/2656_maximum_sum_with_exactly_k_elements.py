# https://leetcode.cn/problems/maximum-sum-with-exactly-k-elements/

class Solution:
    def maximizeSum(self, nums, k):
        """
        Inputs:
            nums: list[int]
            k: int
        Outputs:
            res: int
        """
        m = max(nums)
        res = (m + m+k-1) * k // 2
        return res