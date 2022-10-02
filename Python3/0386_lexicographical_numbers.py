# https://leetcode.cn/problems/lexicographical-numbers/

class Solution:
    def lexicalOrder(self, n):
         """
        Inputs:
            n: int
        Outputs:
            res: list[int]
        """

        res = [1 for _ in range(n)]
        num = 1
        for i in range(n):
            res[i] = num

            tmp = num * 10
            if tmp <= n:
                num = tmp
            else:
                while (num %10 == 9) or (num + 1 > n):
                    num = num // 10
                num = num + 1
        return res