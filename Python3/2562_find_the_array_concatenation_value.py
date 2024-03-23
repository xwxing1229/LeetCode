# https://leetcode.cn/problems/find-the-array-concatenation-value/

class Solution:
    def findTheArrayConcVal(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        res = 0
        i, j = 0, len(nums)-1
        while i < j:
            a, b, num = nums[i], nums[j], nums[j]
            while num > 0:
                num //= 10
                a *= 10
            res += a + b
            i += 1
            j -= 1
        if i == j:
            res += nums[i]
        return res