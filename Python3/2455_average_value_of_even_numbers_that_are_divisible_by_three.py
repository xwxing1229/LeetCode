# https://leetcode.cn/problems/average-value-of-even-numbers-that-are-divisible-by-three/

class Solution:
    def averageValue(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        s, n = 0, 0
        for num in nums:
            if num % 6 == 0:
                s += num
                n += 1
        return s // n if n > 0 else 0