# https://leetcode.cn/problems/total-distance-traveled/

class Solution:
    def distanceTraveled(self, mainTank: int, additionalTank: int) -> int:
        res = 0
        while mainTank >= 5 and additionalTank > 0:
            res += 50
            mainTank -= 4
            additionalTank -= 1
        res += 10 * mainTank
        return res