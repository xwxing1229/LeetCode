# https://leetcode.cn/problems/bulb-switcher/

class Solution:
    def bulbSwitch(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: int
        """

        res = int(sqrt(n+0.5))
        return res