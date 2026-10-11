# https://leetcode.cn/problems/sum-of-squares-of-special-elements/

class Solution:
    def sumOfSquares(self, nums: list[int]) -> int:
        res, n = 0, len(nums)
        for i, num in enumerate(nums):
            if n % (i+1) == 0:
                res += num * num
        return res