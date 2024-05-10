# https://leetcode.cn/problems/count-tested-devices-after-test-operations/

class Solution:
    def countTestedDevices(self, batteryPercentages):
        """
        Inputs:
            batteryPercentages: list[int]
        Outputs:
            res: int
        """
        res = 0
        n = len(batteryPercentages)
        for i, bp in enumerate(batteryPercentages):
            if bp > 0:
                res += 1
                for j in range(i+1, n):
                    batteryPercentages[j] = max(0, batteryPercentages[j]-1)
        return res