# https://leetcode.cn/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

class Solution:
    def countPairs(self, n, edges):
        """
        Inputs:
            n: int
            edges: list[list[int]]
        Outputs:
            res: int
        """
        graph = [[] for _ in range(n)]
        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)

        res = 0
        visited = [0 for _ in range(n)]
        q = deque()
        for i in range(n):
            if visited[i]:
                continue

            q.append(i)
            visited[i] = 1
            cnt = 1
            while len(q) > 0:
                a = q.popleft()
                for b in graph[a]:
                    if not visited[b]:
                        q.append(b)
                        visited[b] = 1
                        cnt += 1
            res += cnt * (n - cnt)
        
        return res//2