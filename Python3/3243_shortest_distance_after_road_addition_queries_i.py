# https://leetcode.cn/problems/shortest-distance-after-road-addition-queries-i/

class Solution:
    def shortestDistanceAfterQueries(self, n, queries):
        """
        Inputs:
            n: int
            queries: list[list[int]]
        Outputs:
            res: list[int]
        """
        dp = [i for i in range(n)]
        come_from = [[] for _ in range(n)]
        res = [0 for _ in range(len(queries))]
        for k, q in enumerate(queries):
            a, b = q[0], q[1]
            come_from[b].append(a)

            dp[b] = min(dp[b], dp[a]+1)
            for i in range(b+1, n):
                dp[i] = min(dp[i], dp[i-1]+1)
                for j in come_from[i]:
                    dp[i] = min(dp[i], dp[j]+1)
            
            res[k] = dp[-1]
        return res
