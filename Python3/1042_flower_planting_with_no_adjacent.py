# https://leetcode.cn/problems/flower-planting-with-no-adjacent/

class Solution:
    def gardenNoAdj(self, n, paths):
        """
        Inputs:
            n: int
            paths: list[list[int]]
        Outputs:
            res: list[int]
        """
        graph = defaultdict(set)
        for x, y in paths:
            graph[x].add(y)
            graph[y].add(x)
        
        valid = [[1,1,1,1] for _ in range(n)]
        res = [1 for _ in range(n)]
        for i in range(n):
            for g, check in enumerate(valid[i]):
                if check:
                    res[i] = g + 1
                    for j in graph[i+1]:
                        valid[j-1][g] = 0
                    break
        return res