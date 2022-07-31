# https://leetcode.cn/problems/range-sum-query-immutable/

class NumArray:
    def __init__(self, nums):
        """
        Inputs:
            nums: list[int]
        """

        n = len(nums)
        self.nsum = [0 for i in range(n+1)]
        for i in range(n):
            self.nsum[i] = self.nsum[i-1] + nums[i]

    def sumRange(self, i, j):
        """
        Inputs:
            i: int
            j: int
        Outputs:
            res: int
        """

        res = self.nsum[j] - self.nsum[i-1]
        return res

# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
