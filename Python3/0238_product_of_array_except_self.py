# https://leetcode.cn/problems/product-of-array-except-self/

class Solution:
    def productExceptSelf(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[int]
        """

        n = len(nums)
        # res[i] = nums[0] * ... * nums[i-1]
        res = [1 for _ in range(n)]
        for i in range(1, n):
            res[i] = res[i-1] * nums[i-1]

        right = nums[n-1]
        for i in range(n-2, -1, -1):
            res[i] = res[i] * right
            right = right * nums[i]
        return res