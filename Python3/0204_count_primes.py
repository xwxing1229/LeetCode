# https://leetcode.cn/problems/count-primes/

class Solution:
    def countPrimes(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: int
        """

        primes = [1 for _ in range(n)]

        res = 0
        for i in range(n):
            if primes[i] == 1:
                res = res + 1

                # k = i
                # tmp = k * i
                # while tmp < n:
                #     primes[tmp] = 0
                #     k = k + 1
                #     tmp = k * i

                for k in range(i, (n-1)//i+1):
                    primes[k*i] = 0

        return res