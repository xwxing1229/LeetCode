# https://leetcode.cn/problems/shortest-path-with-at-most-k-consecutive-identical-characters/

import heapq

class Solution:
    def shortestPath(self, n: int, edges: list[list[int]], labels: str, k: int) -> int:
        graph = [[] for _ in range(n)]
        for u, v, w in edges:
            graph[u].append((v, w))
        # hq = [(d, u, cnt)]
        # d: distance from 0 to u with cnt consecutive identical chars
        #    at the end of str path
        hq = [(0, 0, 1)]
        # dist[u][cnt]: min distance from 0 to u with cnt consecutive identical chars
        #               at the end of str path
        dist = [[float("inf") for _ in range(k+1)] for _ in range(n)]
        while hq:
            d, u, cnt = heapq.heappop(hq)
            if u == n-1:
                return d
            if d > dist[u][cnt]:
                continue
            for v, w in graph[u]:
                cnt_v = cnt + 1 if labels[u] == labels[v] else 1
                d_v = d + w
                if cnt_v <= k and d_v < dist[v][cnt_v]:
                    heapq.heappush(hq, (d_v, v, cnt_v))
                    dist[v][cnt_v] = d_v
        return -1