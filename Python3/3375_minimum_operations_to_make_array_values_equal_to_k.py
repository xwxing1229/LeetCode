# https://leetcode.cn/problems/minimum-operations-to-make-array-values-equal-to-k/

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
        s = set()
        for num in nums:
            if num < k:
                return -1
            if num > k and num not in s:
                s.add(num)
                res += 1
        return res