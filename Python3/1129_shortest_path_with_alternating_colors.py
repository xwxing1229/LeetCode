# https://leetcode.cn/problems/shortest-path-with-alternating-colors/

class Solution:
    def shortestAlternatingPaths(self, n, redEdges, blueEdges):
        """
        Inputs:
            n: int
            redEdges, blueEdges: list[list[int]]
        Outputs:
            res: list[int]
        """
        graph = [[[] for x in range(n)] for color in range(2)]
        for x, y in redEdges:
            graph[0][x].append(y)
        for x, y in blueEdges:
            graph[1][x].append(y)
        
        max_ = 2 ** 31 - 1
        dist = [[max_ for x in range(n)] for color in range(2)]
        dist[0][0] = 0
        dist[1][0] = 0
        q = collections.deque()
        q.append((0,0))
        q.append((0,1))
        while len(q):
            x, color = q.popleft()
            for y in graph[1-color][x]:
                if dist[1-color][y] != max_:
                    continue
                dist[1-color][y] = dist[color][x] + 1
                q.append((y, 1-color))

        res = [-1 for x in range(n)]
        for x in range(n):
            res[x] = min(dist[0][i], dist[1][x])
            if res[x] == max_:
                res[x] = -1
        return res