# https://leetcode.cn/problems/max-value-of-equation/

class Solution:
    def findMaxValueOfEquation(self, points, k):
        """
        Inputs:
            points: list[list[int]]
            k: int
        Outputs:
            res: int
        """
        res = None
        pq = []
        for p in points:
            while pq and p[0] - pq[0][1] > k:
                heapq.heappop(pq)
            if pq:
                tmp = -pq[0][0] + p[0] + p[1]
                if res is None or res < tmp:
                    res = tmp
            heapq.heappush(pq, (p[0]-p[1], p[0]))
        return res