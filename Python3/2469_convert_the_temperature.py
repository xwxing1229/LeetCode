# https://leetcode.cn/problems/convert-the-temperature/

class Solution:
    def convertTemperature(self, celsius):
        """
        Inputs:
            celsius: float
        Outputs:
            res: list[float]
        """
        return [celsius + 273.15, celsius * 1.8 + 32.0]