# https://leetcode.cn/problems/subsets/

class Solution:
    def subsets(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[list[int]]
        """

        self.res = []
        n = len(nums)
        self.backtrack(nums, n, [], 0)
        return self.res

    def backtrack(self, nums, n, tmp, idx):
        self.res.append(tmp)

        for i in range(idx, n):
            self.backtrack(nums, n, tmp+[i+1], i+1)
