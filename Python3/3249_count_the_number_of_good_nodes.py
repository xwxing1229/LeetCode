# https://leetcode.cn/problems/count-the-number-of-good-nodes/

class Solution:
    def countGoodNodes(self, edges):
        """
        Inputs:
            edges: list[list[int]]
        Outputs:
            res: int
        """
        from collections import defaultdict

        self.graph = defaultdict(list)
        for a, b in edges:
            self.graph[a].append(b)
            self.graph[b].append(a)
        self.res = 0
        self.dfs(0, -1)
        return self.res
    
    def dfs(self, cur, father):
        good = True
        size = 0
        total = 1
        for node in self.graph[cur]:
            if node == father:
                continue
            tmp = self.dfs(node, cur)
            if size == 0:
                size = tmp # the first child
            elif size != tmp:
                good = False
            total += tmp
        if good:
            self.res += 1
        return total