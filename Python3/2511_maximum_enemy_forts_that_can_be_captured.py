# https://leetcode.cn/problems/maximum-enemy-forts-that-can-be-captured/

class Solution:
    def captureForts(self, forts):
        """
        Inputs:
            forts: list[int]
        Outputs:
            res: int
        """
        res = 0
        i, n = 0, len(forts)
        while i < n:
            while i < n and forts[i] == 0:
                i += 1
            if i >= n:
                break
            idx, cur = i, forts[i]
            i += 1
            while i < n and forts[i] == 0:
                i += 1
            if i < n and forts[i] + cur == 0:
                res = max(res, i-idx-1)
        return res