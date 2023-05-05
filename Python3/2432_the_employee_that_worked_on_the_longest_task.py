# https://leetcode.cn/problems/the-employee-that-worked-on-the-longest-task/

class Solution:
    def hardestWorker(self, n, logs):
        """
        Inputs:
            n: int
            logs: list[list[int]]
        Outputs:
            res: int
        """
        res, spend = logs[0][0], logs[0][1]
        for i in range(1, len(logs)):
            res_tmp, spend_tmp = logs[i][0], logs[i][1] - logs[i-1][1]
            if spend_tmp > spend:
                res = res_tmp
                spend = spend_tmp
            elif spend_tmp == spend and res_tmp < res:
                res = res_tmp
        return res