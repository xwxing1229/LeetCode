# https://leetcode.cn/problems/maximum-units-on-a-truck/

class Solution:
    def maximumUnits(self, boxTypes, truckSize):
        """
        Inputs:
            boxTypes: list[list[int]]
            truckSize: int
        Outputs:
            res: int
        """
        boxTypes = sorted(boxTypes, key=lambda x: -x[1])
        res = 0
        box = 0
        while truckSize > 0 and box < len(boxTypes):
            num = min(truckSize, boxTypes[box][0])
            res += (num * boxTypes[box][1])
            truckSize -= num
            box += 1
        return res