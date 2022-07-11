# https://leetcode.cn/problems/combination-sum-iii/

class Solution:
    def combinationSum3(self, k, n):
        """
        Inputs:
            k: int
            n: int
        Outputs:
            res: list[list[int]]
        """

        self.res = []
        self.backtrack(k, n, [], 0, 1)
        return self.res

    def backtrack(self, k, n, tmp, tmp_sum, idx):
        if len(tmp) == k:
            if tmp_sum == n:
                self.res.append(tmp)
            return

        for i in range(idx, 10):
            self.backtrack(k, n, tmp+[i], tmp_sum+i, i+1)

solu = Solution()
print(solu.combinationSum3(3, 7))