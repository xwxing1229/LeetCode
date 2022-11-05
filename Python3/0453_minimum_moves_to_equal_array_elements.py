# https://leetcode.cn/problems/minimum-moves-to-equal-array-elements/

class Solution:
    def minMoves(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        # Increasing n-1 elements by 1 works similarly as decreasing 1 element by 1.
        min_ = min(nums)
        res = 0
        for num in nums:
            res += (num - min_)
        return res