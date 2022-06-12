# https://leetcode.cn/problems/combinations/

class Solution:
    def combine(self, n, k):
        """
        Inputs:
            n: int
            k: int
        Outputs:
            res: list[list[int]]
        """

        self.res = []
        check = [0 for _ in range(n)]
        self.backtrack(n, k, check, [], 0)
        return self.res

    def backtrack(self, n, k, check, tmp, idx):
        if len(tmp) == k:
            self.res.append(tmp)
            return

        for i in range(idx, n):
            if check[i]:
                continue

            check[i] = 1
            self.backtrack(n, k, check, tmp+[i+1], i)
            check[i] = 0
