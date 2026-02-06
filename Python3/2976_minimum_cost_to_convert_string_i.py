# https://leetcode.cn/problems/minimum-cost-to-convert-string-i/

import heapq

class Solution:
    def minimumCost(self, source: str, target: str, original: list[str], changed: list[str], cost: list[int]) -> int:        
        def updateCostMinFromNode(node):
            nonlocal cost_min

            pq = [(0, node)]
            while pq:
                c_curr, curr = heapq.heappop(pq)
                if cost_min[node][curr] < c_curr:
                    continue
                cost_min[node][curr] = c_curr
                for next in range(26):
                    if graph[curr][next] < 0:
                        continue
                    c_next = c_curr + graph[curr][next]
                    if cost_min[node][next] > c_next:
                        heapq.heappush(pq, (c_next, next))

        graph = [[-1 for _ in range(26)] for _ in range(26)]
        for i in range(len(original)):
            node0 = ord(original[i]) - ord("a")
            node1 = ord(changed[i]) - ord("a")
            if graph[node0][node1] < 0 or graph[node0][node1] > cost[i]:
                graph[node0][node1] = cost[i]

        cost_min = [[float("inf") for _ in range(26)] for _ in range(26)]
        for node in range(26):
            cost_min[node][node] = 0
        for node in range(26):
            updateCostMinFromNode(node)

        res = 0
        for i in range(len(source)):
            node0 = ord(source[i]) - ord("a")
            node1 = ord(target[i]) - ord("a")
            if cost_min[node0][node1] == float("inf"):
                return -1
            res += cost_min[node0][node1]
        return res