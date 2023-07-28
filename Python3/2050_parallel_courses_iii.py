# https://leetcode.cn/problems/parallel-courses-iii/

class Solution:
    def minimumTime(self, n, relations, time):
        """
        Inputs:
            n: int
            relations: list[list[int]]
            time: list[int]
        Outputs:
            res: int
        """
        self.prerequisite = [[] for _ in range(n)]
        for x, y in relations:
            self.prerequisite[y-1].append(x-1)

        res = 0
        self.check = [0 for _ in range(n)]
        self.time = time
        for course in range(n):
            res = max(res, self.dfs(course))
        return res

    def dfs(self, cur):
        if self.check[cur] != 0:
            return self.check[cur]

        tmp = 0
        for course in self.prerequisite[cur]:
            tmp = max(tmp, self.dfs(course))
        self.check[cur] = tmp + self.time[cur]

        return self.check[cur]