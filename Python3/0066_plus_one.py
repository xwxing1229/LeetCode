# https://leetcode.cn/problems/plus-one/

class Solution:
    def plusOne(self, digits: list[int]) -> list[int]:
        carry = 1
        for i in range(len(digits)-1, -1, -1):
            num = digits[i] + carry
            digits[i] = num % 10
            carry = num // 10
            if carry == 0:
                break
        if carry:
            digits = [1] + digits
        return digits