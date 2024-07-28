# https://leetcode.cn/problems/detonate-the-maximum-bombs/

class Solution:
    def maximumDetonation(self, bombs):
        """
        Inputs:
            bombs: list[list[int]]
        Outputs:
            res: int
        """
        n = len(bombs)
        graph = [[] for _ in range(n)]
        for i, a in enumerate(bombs):
            xa, ya, ra = a
            for j in range(i+1, n):
                xb, yb, rb = bombs[j]
                dsq = (xb-xa)*(xb-xa) + (yb-ya)*(yb-ya)
                if dsq <= ra*ra:
                    graph[i].append(j)
                if dsq <= rb*rb:
                    graph[j].append(i)
        
        res = 1
        for i in range(n):
            tmp = 1
            q = deque()
            q.append(i)
            visited = [0 for _ in range(n)]
            visited[i] = 1
            while q:
                cur = q.popleft()
                for node in graph[cur]:
                    if visited[node] == 0:
                        tmp += 1
                        q.append(node)
                        visited[node] = 1
            res = max(res, tmp)
        return res