# https://leetcode.cn/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

class Solution:
    def minReorder(self, n, connections):
        """
        Inputs:
            n: int
            connections: list[list[int]]
        Outputs:
            res: int
        """
        graph = [[] for _ in range(n)]
        pairs = set()
        for a, b in connections:
            graph[a].append(b)
            graph[b].append(a)
            pairs.add((a, b))
        
        res = 0
        q = deque()
        q.append(0)
        visited = [0 for _ in range(n)]
        visited[0] = 1
        while len(q) > 0:
            cur = q.popleft()
            for node in graph[cur]:
                if visited[node]:
                    continue
                if (node, cur) not in pairs:
                    res += 1
                q.append(node)
                visited[node] = 1
        return res