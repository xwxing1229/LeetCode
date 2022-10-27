# https://leetcode.cn/problems/sign-of-the-product-of-an-array/

class Solution:
    def arraySign(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        res = 1
        for i in nums:
            if i < 0:
                res = -res
            elif i == 0:
                return 0
        return res