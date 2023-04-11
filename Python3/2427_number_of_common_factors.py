# https://leetcode.cn/problems/number-of-common-factors/

class Solution:
    def commonFactors(self, a, b):
        """
        Inputs:
            a, b: int
        Outputs:
            res: int
        """
        factor_a = set()
        for i in range(1, int(sqrt(a)) + 1):
            if a % i == 0:
                factor_a.add(i)
                factor_a.add(a // i)
        res = 0
        for i in range(1, int(sqrt(b)) + 1):
            if b % i == 0:
                if i in factor_a:
                    res += 1
                j = b // i
                if j != i and j in factor_a:
                    res += 1
        return res