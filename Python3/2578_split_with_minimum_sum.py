# https://leetcode.cn/problems/split-with-minimum-sum/

class Solution:
    def splitNum(self, num):
        """
        Inputs:
            num: int
        Outputs:
            res: int
        """
        digits = []
        n = num
        while n > 0:
            digits.append(n % 10)
            n //= 10
        digits.sort()
        
        num1, num2 = 0, 0
        for i in range(1, len(digits), 2):
            num1 = num1 * 10 + digits[i-1]
            num2 = num2 * 10 + digits[i]
        if len(digits) % 2 == 1:
            num1 = num1 * 10 + digits[-1]
        return num1 + num2