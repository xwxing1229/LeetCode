# https://leetcode.cn/problems/matchsticks-to-square/

class Solution:
    def makesquare(self, matchsticks):
        """
        Inputs:
            matchsticks: list[int]
        Outputs:
            res: bool
        """
        s = sum(matchsticks)
        if s % 4 != 0:
            return False
        avg = s // 4
        edges = [0, 0, 0, 0]
        matchsticks.sort(reverse=True)

        def dfs(cur):
            if cur == len(matchsticks):
                return True
            for i in range(4):
                edges[i] += matchsticks[cur]
                if edges[i] <= avg and dfs(cur+1):
                    return True
                edges[i] -= matchsticks[cur]
            return False
            
        res = dfs(0)
        return res