# https://leetcode.cn/problems/count-odd-numbers-in-an-interval-range/

class Solution:
    def countOdds(self, low: int, high: int) -> int:
        res = (high - low + 1) // 2
        if low % 2 and high % 2:
            res += 1
        return res