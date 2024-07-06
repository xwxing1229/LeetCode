# https://leetcode.cn/problems/maximum-path-quality-of-a-graph/

class Solution:
    def maximalPathQuality(self, values, edges, maxTime):
        """
        Inputs:
            values: list[int]
            edges: list[list[int]]
            maxTime: int
        Outputs:
            res: int
        """
        self.graph = defaultdict(list)
        for a, b, t in edges:
            self.graph[a].append([b, t])
            self.graph[b].append([a, t])
        
        self.values = values
        self.maxTime = maxTime
        
        self.res = 0
        visited = [0 for _ in range(len(values))]
        visited[0] = 1
        self.dfs(0, values[0], 0, visited)
        return self.res
        
    def dfs(self, cur, val, tused, visited):
        if cur == 0 and tused <= self.maxTime:
            self.res = max(self.res, val)
        for node, t in self.graph[cur]:
            if tused + t > self.maxTime:
                continue
            if visited[node]:
                self.dfs(node, val, tused+t, visited)
            else:
                visited[node] = 1
                self.dfs(node, val+self.values[node], tused+t, visited)
                visited[node] = 0