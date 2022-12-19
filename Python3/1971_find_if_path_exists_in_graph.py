# https://leetcode.cn/problems/find-if-path-exists-in-graph/

class Solution:
    def validPath(self, n, edges, source, destination):
        """
        Inputs:
            n: int
            edges: list[list[int]]
            source: int
            destination: int
        Outputs:
            res: bool
        """
        if n == 1:
            return True
        graph = collections.defaultdict(list)
        for n1, n2 in edges:
            graph[n1].append(n2)
            graph[n2].append(n1)
        q = collections.deque()
        q.append(source)
        visited = [0 for _ in range(n)]
        visited[source] = 1
        while len(q) > 0:
            cur = q.popleft()
            for node in graph[cur]:
                if node == destination:
                    return True
                if visited[node] < 1:
                    q.append(node)
                    visited[node] = 1
        return False