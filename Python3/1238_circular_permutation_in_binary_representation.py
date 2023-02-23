# https://leetcode.cn/problems/circular-permutation-in-binary-representation/

class Solution:
    def circularPermutation(self, n, start):
        """
        Inputs:
            n: int
            start: int
        Outputs:
            res: list[int]
        """
        res = [0, 1]
        size, digits = 2**n, 1
        while len(res) < size:
            size_cur = len(res)
            base = 1 << digits
            for i in range(size_cur-1, -1, -1):
                res.append(base + res[i])
            digits += 1
        
        k = 0
        while res[k] != start:
            k += 1
        res = res[k:] + res[:k]
        return res