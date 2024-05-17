# https://leetcode-cn.com/problems/most-profit-assigning-work/
class Solution:
    def maxProfitAssignment(self, difficulty, profit, worker):
        """
        Inputs:
            difficulty, profit, worker: list[int]
        Outputs:
            res: int
        """

        n = len(difficulty)
        work = [(difficulty[i], profit[i]) for i in range(n)]
        work.sort()
        worker.sort()

        res = 0
        i, p_max = 0, 0
        for w in worker:
            while i < n and work[i][0] <= w:
                p_max = max(p_max, work[i][1])
                i += 1
            res += p_max
        return res