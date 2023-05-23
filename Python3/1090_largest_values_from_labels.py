# https://leetcode.cn/problems/largest-values-from-labels/

class Solution:
    def largestValsFromLabels(self, values, labels, numWanted, useLimit):
        """
        Inputs:
            values, labels: list[int]
            numWanted, useLimit: int
        Outputs:
            res: int
        """
        idxs = [i for i in range(len(values))]
        idxs.sort(key=values.__getitem__)
        res, n = 0, 0
        cnt = defaultdict(int)
        for i in range(len(idxs)-1, -1, -1):
            idx = idxs[i]
            if n == numWanted:
                break
            if cnt[labels[idx]] < useLimit:
                res += values[idx]
                cnt[labels[idx]] += 1
                n += 1
        return res