# https://leetcode.cn/problems/find-the-key-of-the-numbers/

class Solution:
    def generateKey(self, num1: int, num2: int, num3: int) -> int:
        res, pow10 = 0, 1
        for i in range(4):
            res += min(num1%10, num2%10, num3%10) * pow10
            pow10 *= 10
            num1 //= 10
            num2 //= 10
            num3 //= 10
        return res
    
