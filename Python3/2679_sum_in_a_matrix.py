# https://leetcode.cn/problems/sum_in_a_matrix/

class Solution:
    def matrixSum(self, nums):
        """
        Inputs:
            nums: list[list[int]]
        Outputs:
            res: int
        """
        m, n = len(nums), len(nums[0])
        for i in range(m):
            nums[i] = sorted(nums[i], reverse=True)
        res = 0
        for j in range(n):
            max_ = nums[0][j]
            for i in range(m):
                max_ = max(max_, nums[i][j])
            res += max_
        return res