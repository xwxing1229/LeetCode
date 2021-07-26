# https://leetcode-cn.com/problems/most-profit-assigning-work/
class Solution:
    def maxProfitAssignment(self, difficulty, profit, worker):
        """
        Inputs:
            difficulty: list[int]
            profit: list[int]
            worker: list[int]
        Outputs:
            res: int
        """

        n = len(difficulty)
        work = []
        for i in range(n):
            work.append((difficulty[i], profit[i]))
        work.sort()

        res = 0
        max_profit = 0 # maximum profit until current work
        i = 0
        worker.sort()
        for w in worker:
            while i < n and w >= work[i][0]:
                if work[i][1] > max_profit:
                    max_profit = work[i][1]
                i = i + 1

            res = res + max_profit

        return res