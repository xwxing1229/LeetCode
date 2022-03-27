# https://leetcode-cn.com/problems/longest-harmonious-subsequence/
class Solution:
    def findLHS(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        count = {}
        for i in nums:
            count[i] = count.get(i,0) + 1

        res = 0
        for i in count:
            tmp = count[i]
            res = max(res, tmp + count.get(i+1,-tmp))
        return res