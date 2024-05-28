# https://leetcode.cn/problems/find-missing-observations/

class Solution:
    def missingRolls(self, rolls, mean, n):
        """
        Inputs:
            rolls: list[int]
            mean, n: int
        Outputs:
            res: list[int]
        """
        m = len(rolls)
        s, sm = mean * (m+n), sum(rolls)
        sn = s - sm
        if sn < n or sn > 6*n:
            return []
        
        res = [1 for _ in range(n)]
        sn -= n
        for i in range(n):
            add = min(5, sn)
            res[i] += add
            sn -= add
            if sn == 0:
                break
        return res