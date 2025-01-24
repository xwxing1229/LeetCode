# https://leetcode.cn/problems/node-with-highest-edge-score/

class Solution:
    def edgeScore(self, edges):
        """
        Inputs:
            edges: list[int]
        Outputs:
            res: int
        """
        n = len(edges)
        cnts = [0 for _ in range(n)]
        for i, node in enumerate(edges):
            cnts[node] += i
        res = 0
        cnt_max = cnts[0]
        for node, cnt in enumerate(cnts):
            if cnt > cnt_max:
                res = node
                cnt_max = cnt
        return res