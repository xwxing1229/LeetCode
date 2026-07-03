# https://leetcode.cn/problems/network-recovery-pathways/

class Solution:
    def findMaxPathScore(self, edges: list[list[int]], online: list[bool], k: int) -> int:
        n = len(online)
        graph = [[] for _ in range(n)]
        left, right = float("inf"), 0
        for u, v, c in edges:
            if online[u] and online[v]:
                graph[u].append((v, c))
                left = min(left, c)
                right = max(right, c)
        
        def check(score) -> bool:
            record = [-1 for _ in range(n)]
            record[n-1] = 0
            def dfs(u: int) -> int:
                if (record[u] >= 0):
                    return record[u]
                res = float("inf")
                for v, c in graph[u]:
                    if c >= score:
                        res = min(res, dfs(v) + c)
                record[u] = res
                return res
            return dfs(0) <= k
        
        res = -1
        while left <= right:
            mid = (left + right) // 2
            if check(mid):
                res = mid
                left = mid + 1
            else:
                right = mid - 1
        return res if res >= -1 else -1