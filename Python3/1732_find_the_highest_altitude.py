# https://leetcode.cn/problems/find-the-highest-altitude/

class Solution:
    def largestAltitude(self, gain: list[int]) -> int:
        curr, res = 0, 0
        for g in gain:
            curr += g
            res = max(res, curr)
        return res