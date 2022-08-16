# https://leetcode.cn/problems/counting-bits/

class Solution:
    def countBits(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: list[int]
        """
        res = [0 for _ in range(n+1)]
        k = 0
        pow2 = 1
        for i in range(1, n+1):
            res[i] = res[k] + 1
            k = k + 1
            if k == pow2:
                k = 0
                pow2 = pow2 * 2
        return res