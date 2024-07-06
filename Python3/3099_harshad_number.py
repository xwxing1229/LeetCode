# https://leetcode.cn/problems/harshad-number/

class Solution:
    def sumOfTheDigitsOfHarshadNumber(self, x: int) -> int:
        res, num = 0, x
        while num > 0:
            res += num % 10
            num //=10
        return res if x % res == 0 else -1