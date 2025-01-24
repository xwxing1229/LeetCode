# https://leetcode.cn/problems/difference-between-element-sum-and-digit-sum-of-an-array/

class Solution:
    def differenceOfSum(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        s_element, s_digit = 0, 0
        for num in nums:
            s_element += num
            val = num
            while val > 0:
                s_digit += val % 10
                val //= 10
        return abs(s_element - s_digit)