# https://leetcode.cn/problems/find-the-peaks/

class Solution:
    def findPeaks(self, mountain):
        """
        Inputs:
            moutain: list[int]
        Outputs:
            res: list[int]
        """
        res = []
        i, n = 1, len(mountain)
        while i < n-1:
            cur = mountain[i]
            if cur > mountain[i-1] and cur > mountain[i+1]:
                res.append(i)
                i += 2
            else:
                i += 1
        return res