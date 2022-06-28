# https://leetcode.cn/problems/gas-station/

class Solution:
    def canCompleteCircuit(self, gas, cost):
        """
        Inputs:
            gas: list[int]
            cost: list[int]
        Outputs:
            res: int
        """

        # If start -> idx is not possible, check from idx rather than start+1.
        start = -1
        idx = 0
        n = len(gas)
        while start < idx:
            start = idx
            g = gas[idx]
            while g >= 0:
                g = g - cost[idx]
                idx = (idx + 1) % n

                if g >= 0:
                    g = g + gas[idx]
                    if idx == start:
                        return start

        return -1