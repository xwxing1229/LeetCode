# https://leetcode-cn.com/problems/squares-of-a-sorted-array/
class Solution:
    def sortedSquares(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[int]
        """

        res = [0 for _ in range(len(nums))]
        for i, num in enumerate(nums):
            res[i] = num * num
        res.sort()
        return res