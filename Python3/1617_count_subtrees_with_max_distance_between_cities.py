# https://leetcode.cn/problems/count-subtrees-with-max-distance-between-cities/

class Solution:
    def countSubgraphsForEachDiameter(self, n, edges):
        """
        Inputs:
            n: int
            edges: list[list[int]]
        Outputs:
            res: list[int]
        """
        self.graph = defaultdict(list)
        for u, v in edges:
            self.graph[u-1].append(v-1)
            self.graph[v-1].append(u-1)

        self.res = [0 for _ in range(n-1)]
        for mask in range(3, 1 << n):
            if mask & (mask - 1) == 0:
                continue
            self.start = mask.bit_length() - 1 # choose a start node
            # If the current mask is valid, change the start node, compute the diameter,
            # and update the result.
            if self.bfs(mask):
                self.bfs(mask, True)
        return self.res
    
    def bfs(self, mask, update=False):
        q = deque()
        q.append(self.start)
        mask ^= (1 << self.start)
        dist = -1
        while len(q):
            dist += 1
            n = len(q)
            for _ in range(n):
                cur = q.popleft()
                self.start = cur
                for neigh in self.graph[cur]:
                    if (mask >> neigh) & 1:
                        q.append(neigh)
                        mask ^= (1 << neigh)
        if mask == 0:
            if update:
                self.res[dist-1] += 1
            return True
        else:
            return False