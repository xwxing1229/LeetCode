# https://leetcode.cn/problems/smallest-integer-divisible-by-k/

class Solution:
    def smallestRepunitDivByK(self, k):
        """
        Inputs:
            k: int
        Outputs:
            res: int
        """
        res, rem = 1, 1%k
        check = [0 for _ in range(k)]
        while rem != 0:
            res += 1
            check[rem] = 1
            rem = (rem * 10 + 1) % k
            if check[rem]:
                return -1
        return res