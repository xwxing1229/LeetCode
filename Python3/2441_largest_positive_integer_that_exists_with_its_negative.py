# https://leetcode.cn/problems/largest-positive-integer-that-exists-with-its-negative/

class Solution:
    def findMaxK(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        check = [0 for i in range(1001)]
        for i in nums:
            if i < 0:
                check[-i] = 1
        res = -1
        for i in nums:
            if i > 0 and check[i] == 1 and i > res:
                res = i
        return res