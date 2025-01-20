# https://leetcode.cn/problems/maximum-number-of-eaten-apples/

class Solution:
    def eatenApples(self, apples, days):
        """
        Inputs:
            apples, days: list[int]
        Outputs:
            res: int
        """
        res = 0
        valid = []
        i, n = 0, len(apples)
        while i < n or valid:
            if i < n and apples[i] > 0:
                heapq.heappush(valid, (i+days[i]-1, apples[i]))
            while valid:
                x = heapq.heappop(valid)
                if i <= x[0]:
                    res += 1
                    if x[1] > 1:
                        heapq.heappush(valid, (x[0], x[1]-1))
                    break
            i += 1
        return res