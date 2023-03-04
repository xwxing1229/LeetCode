# https://leetcode.cn/problems/total-hamming-distance/

class Solution:
    def totalHammingDistance(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        res, n = 0, len(nums)
        for i in range(30):
            ones = 0
            for num in nums:
                ones += ((num >> i) & 1)
            res += ones * (n - ones)
        return res