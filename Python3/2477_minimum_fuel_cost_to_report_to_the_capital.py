# https://leetcode.cn/problems/minimum-fuel-cost-to-report-to-the-capital/

class Solution:
    def minimumFuelCost(self, roads, seats):
        """
        Inputs:
            roads: list[list[int]]
            seats: int
        Outputs:
            res: int
        """
        graph = defaultdict(list)
        for a, b in roads:
            graph[a].append(b)
            graph[b].append(a)
        
        res = 0
        def dfs(cur, parent):
            nonlocal res
            total = 1
            for node in graph[cur]:
                if node != parent:
                    people = dfs(node, cur)
                    res += (people + seats - 1) // seats
                    total += people
            return total
        
        dfs(0, -1)
        return res