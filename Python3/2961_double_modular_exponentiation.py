# https://leetcode.cn/problems/double-modular-exponentiation/

class Solution:
    def getGoodIndices(self, variables, target):
        """
        Inputs:
            variables: list[list[int]]
            target: int
        Outputs:
            res: list[int]
        """
        remainders = [[i] for i in range(10)]
        for i in range(10):
            val = i * i % 10
            while remainders[i][0] != val:
                remainders[i].append(val)
                val *= i
                val %= 10
        res = []
        for idx, (ai, bi, ci, mi) in enumerate(variables):
            if target >= mi:
                continue
            tmp = remainders[ai%10][bi % len(remainders[ai%10]) - 1]
            # Check if tmp ^ ci % mi == target.
            val, cnt = 1, 0
            while cnt < ci:
                val = val * tmp % mi
                cnt += 1
            if val % mi == target:
                res.append(idx)
        return res