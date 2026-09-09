# https://leetcode.cn/problems/count-commas-in-range-ii/

class Solution:
    def countCommas(self, n: int) -> int:
        cnt, num = 0, n
        while num > 0:
            num //= 1000
            cnt += 1
        res = 0
        left = 1000
        for c in range(1, cnt):
            tmp = left * 1000
            right = min(tmp - 1, n)
            res += (right - left + 1) * c
            left = tmp
        return res