# https://leetcode.cn/problems/best-sightseeing-pair/

class Solution:
    def maxScoreSightseeingPair(self, values):
        """
        Inputs:
            values: list[int]
        Outputs:
            res: int
        """
        n = len(values)
        # For j = 0, 1, ..., n-1,
        # right_max[j] = max(values[j]-j, values[j+1]-(j+1), ..., values[n-1]-(n-1)).
        right_max = [values[-1]-(n-1) for _ in range(n)]
        for j in range(n-2, -1, -1):
            right_max[j] = max(values[j]-j, right_max[j+1])
        
        res = values[0] + 0 + right_max[1]
        for i in range(n-1):
            res = max(res, values[i] + i + right_max[i+1])
        return res