# https://leetcode.cn/problems/find-the-prefix-common-array-of-two-arrays/

class Solution:
    def findThePrefixCommonArray(self, A: list[int], B: list[int]) -> list[int]:
        n = len(A)
        check = [[0 for _ in range(n+1)] for _ in range(2)]
        check[0][A[0]] = 1
        check[1][B[0]] = 1
        res = [0 for _ in range(n)]
        res[0] += (A[0] == B[0])
        for i in range(1, n):
            a, b = A[i], B[i]
            check[0][a] = 1
            check[1][b] = 1
            print(check)
            res[i] = res[i-1] + check[1][a] + check[0][b] - (a == b)
        return res