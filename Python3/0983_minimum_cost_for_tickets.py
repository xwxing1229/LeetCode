# https://leetcode.cn/problems/minimum-cost-for-tickets/


class Solution:
    def mincostTickets(self, days, costs):
        """
        Inputs:
            days, costs: list[int]
        Outputs:
            res: int
        """
        dp = [0 for _ in range(days[-1]+1)]
        s = set(days)
        for i in range(1, days[-1]+1):
            if i not in s:
                dp[i] = dp[i-1]
            else:
                dp[i] = min(dp[i-1] + costs[0],
                            dp[max(i-7, 0)] + costs[1],
                            dp[max(i-30, 0)] + costs[2])
        return dp[-1]