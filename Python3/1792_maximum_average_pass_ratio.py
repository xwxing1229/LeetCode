# https://leetcode.cn/problems/maximum-average-pass-ratio/

class Solution:
    def maxAverageRatio(self, classes, extraStudents):
        """
        Inputs:
            classes: list[list[int]]
            extraStudents: int
        Outputs:
            res: float
        """
        res = 0
        pq = []
        for p, t in classes:
            heapq.heappush(pq, ((p-t) / (t * (t+1)), p, t)) #  -((p+1)/(t+1) - p/t)
            res += p / t
        for i in range(extraStudents):
            incre, p, t = heapq.heappop(pq)
            res -= incre
            heapq.heappush(pq, ((p-t) / ((t+1) * (t+2)), p+1, t+1))
        res /= len(pq)
        return res