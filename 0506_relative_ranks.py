# https://leetcode-cn.com/problems/relative-ranks/

class Solution:
    def findRelativeRanks(self, score):
        """
        Inputs:
            score: list[int]
        Outputs:
            res: list[str]
        """

        n = len(score)

        # Record indices corresponding to the scores.
        mapping = {}
        for i in range(n):
            mapping[score[i]] = i

        rank = sorted(mapping.items(), key=lambda x:-x[0])

        res = [0 for i in range(n)]
        for i in range(n):
            if i == 0:
                res[rank[i][1]] = 'Gold Medal'
            elif i == 1:
                res[rank[i][1]] = 'Silver Medal'
            elif i == 2:
                res[rank[i][1]] = 'Bronze Medal'
            else:
                res[rank[i][1]] = str(i+1)
        return res