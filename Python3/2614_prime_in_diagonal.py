# https://leetcode.cn/problems/prime-in-diagonal/

import math

class Solution:
    def diagonalPrime(self, nums) -> int:
        """
        Inputs:
            nums: list[list[int]]
        Outputs:
            res: int
        """
        def is_prime(num: int):
            for x in range(2, int(math.sqrt(num))+1):
                if num % x == 0:
                    return False
            return num > 1
        
        res = 0
        n = len(nums)
        for i in range(n):
            num1, num2 = nums[i][i], nums[i][n-1-i]
            if is_prime(num1) and num1 > res:
                res = num1
            if is_prime(num2) and num2 > res:
                res = num2

        return res