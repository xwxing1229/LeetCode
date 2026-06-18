# https://leetcode.cn/problems/angle-between-hands-of-a-clock/

class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        h = (minutes / 60 + hour) * 5
        res = abs(h - minutes) * 6
        return res if res <= 180 else 360 - res