# https://leetcode.cn/problems/number-of-employees-who-met-the-target/

class Solution:
    def numberOfEmployeesWhoMetTarget(self, hours, target):
        """
        Inputs:
            hours: list[int]
            target: int
        Outputs:
            res: int
        """
        res = 0
        for h in hours:
            if h >= target:
                res += 1
        return res