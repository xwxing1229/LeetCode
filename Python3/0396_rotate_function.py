# https://leetcode.cn/problems/rotate-function/

class Solution:
    def maxRotateFunction(self, nums: list[int]) -> int:
        f, s = 0, 0
        for i, num in enumerate(nums):
            f += i * num
            s += num
        res = f
        n = len(nums)
        for i in range(1, n):
            f = f + s - n * nums[n-i]
            res = max(res, f)
        return res