# https://leetcode.cn/problems/sequential-digits/

class Solution:
    def sequentialDigits(self, low: int, high: int) -> list[int]:
        def count(num):
            res = 0
            while num > 0:
                num //= 10
                res += 1
            return res
        
        res = []
        digits_low, digits_high = count(low), count(high)
        for digit in range(digits_low, digits_high+1):
            curr, d = 0, 1
            add = 0
            for _ in range(digit):
                curr = curr * 10 + d
                d += 1
                add = add * 10 + 1
            while curr % 10 != 0 and curr <= high:
                if curr >= low:
                    res.append(curr)
                curr += add
        return res