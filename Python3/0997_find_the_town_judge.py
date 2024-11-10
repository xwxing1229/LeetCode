# https://leetcode.cn/problems/find-the-town-judge/

class Solution:
    def findJudge(self, n, trust):
        """
        Inputs:
            n: int
            trust: list[list[int]]
        OUtputs:
            res: int
        """

        judge = [1 for _ in range(n+1)]
        cnts = [0 for _ in range(n+1)]
        for a, b in trust:
            judge[a] = 0
            cnts[b] += 1
        for i in range(1, n+1):
            if cnts[i] == n-1 and judge[i]:
                return i
        return -1