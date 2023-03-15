# https://leetcode.cn/problems/maximal-network-rank/
        
class Solution:
    def maximalNetworkRank(self, n, roads):
        """
        Inputs:
            n: int
            roads: list[list[int]]
        Outputs:
            res: int
        """
        cnt = defaultdict(int)
        connect = [[0 for _ in range(n)] for _ in range(n)]
        for x, y in roads:
            cnt[x] += 1
            cnt[y] += 1
            connect[x][y] = 1
            connect[y][x] = 1

        res = 0
        for i in range(n):
            for j in range(i+1, n):
                tmp = cnt[i] + cnt[j] - connect[i][j]
                if tmp > res:
                    res = tmp
        return res