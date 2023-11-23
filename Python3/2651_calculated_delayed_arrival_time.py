# https://leetcode.cn/problems/calculate-delayed-arrival-time/

class Solution:
    def findDelayedArrivalTime(self, arrivalTime, delayedTime):
        """
        Inputs:
            arrivalTime, delayedTime: int
        Outputs:
            res: int
        """
        return (arrivalTime + delayedTime) % 24