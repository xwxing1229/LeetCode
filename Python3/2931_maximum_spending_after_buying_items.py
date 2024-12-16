# https://leetcode.cn/problems/maximum-spending-after-buying-items/

class Solution:
    def maxSpending(self, values):
        """
        Inputs:
            values: list[list[int]]
        Outputs:
            res: int
        """
        m, n = len(values), len(values[0])
        items = [(values[i][-1], i) for i in range(m)]
        heapq.heapify(items)

        res = 0
        idxs = [n-1 for _ in range(m)]
        days = 1
        while items:
            val, i = heapq.heappop(items)
            res += val * days
            days += 1
            idxs[i] -= 1
            if idxs[i] >= 0:
                heapq.heappush(items, (values[i][idxs[i]], i))
        return res