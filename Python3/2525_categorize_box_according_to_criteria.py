# https://leetcode.cn/problems/categorize-box-according-to-criteria/

class Solution:
    def categorizeBox(self, length, width, height, mass):
        """
        Inputs:
            length, width, height, mass: int
        Outputs:
            res: str
        """
        bulky, heavy = False, False
        L, V, M = 1e4, 1e9, 100
        if length >= L or width >= L or height >= L or length * width >= V / height:
            bulky = True
        if mass >= M:
            heavy = True
        if bulky and heavy:
            return "Both"
        elif bulky and not (heavy):
            return "Bulky"
        elif (not bulky) and heavy:
            return "Heavy"
        else:
            return "Neither"