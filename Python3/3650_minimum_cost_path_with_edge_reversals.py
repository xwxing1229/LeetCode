# https://leetcode.cn/problems/minimum-cost-path-with-edge-reversals/

import heapq

class Solution:
    def minCost(self, n: int, edges: list[list[int]]) -> int:
        graph = [[] for _ in range(n)]
        for u, v, w in edges:
            graph[u].append((v, w))
            graph[v].append((u, w+w))
        
        dist = [float("inf") for _ in range(n)]
        dist[0] = 0
        pq = [(0, 0)]
        while pq:
            cur, d_cur = heapq.heappop(pq)
            if d_cur > dist[cur]:
                continue
            if cur == n-1:
                return d_cur
            for node, w in graph[cur]:
                d_node = d_cur + w
                if d_node < dist[node]:
                    dist[node] = d_node
                    heapq.heappush(pq, (node, d_node))
        return -1