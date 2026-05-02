# https://leetcode.cn/problems/rotated-digits/

class Solution:
    def rotatedDigits(self, n: int) -> int:
        res = 0
        for i in range(1, n+1):
            num = i
            all_valid, has_diff = True, False
            while num > 0:
                digit = num % 10
                if digit == 3 or digit == 4 or digit == 7:
                    all_valid = False
                    break
                elif digit == 2 or digit == 5 or digit == 6 or digit == 9:
                    has_diff = True
                num //= 10
            if all_valid and has_diff:
                res += 1
        return res