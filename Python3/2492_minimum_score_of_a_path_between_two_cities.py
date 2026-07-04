# https://leetcode.cn/problems/minimum-score-of-a-path-between-two-cities/

from collections import deque

class Solution:
    def minScore(self, n: int, roads: list[list[int]]) -> int:
        graph = [[] for _ in range(n+1)]
        distance = [float("inf") for _ in range(n+1)]
        for a, b, d in roads:
            graph[a].append(b)
            graph[b].append(a)
            distance[a] = min(distance[a], d)
            distance[b] = min(distance[b], d)

        res = distance[1]
        connect = [False for _ in range(n+1)]
        connect[1] = True
        q = deque()
        q.append(1)
        while q:
            a = q.pop()
            for b in graph[a]:
                if not connect[b]:
                    res = min(res, distance[b])
                    connect[b] = True
                    q.append(b)
        return res