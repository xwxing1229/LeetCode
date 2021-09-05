# https://leetcode-cn.com/problems/two-city-scheduling/
class Solution:
    def twoCitySchedCost(self, costs):
        """
        Inputs:
            costs: list[list[int]]
        Outputs:
            res: int
        """

        n = len(costs)
        sum_b = 0
        for i in costs:
            sum_b = sum_b + i[1]

        diff = [0 for _ in range(n)]
        for i in range(n):
            diff[i] = costs[i][0] - costs[i][1]
        diff.sort()

        res = sum_b + sum(diff[:n//2])
        return res