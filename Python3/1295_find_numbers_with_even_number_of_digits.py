# https://leetcode.cn/problems/find-numbers-with-even-number-of-digits/

class Solution:
    def findNumbers(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        def digits(num):
            res = 0
            while num:
                res += 1
                num //= 10
            return res
        
        res = len(nums)
        for num in nums:
            res -= digits(num) % 2
        return res