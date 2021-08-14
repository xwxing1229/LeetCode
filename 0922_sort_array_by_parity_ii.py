# https://leetcode-cn.com/problems/sort-array-by-parity-ii/
class Solution:
    def sortArrayByParityII(self, nums, k):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[int]
        """

        n = len(nums)
        res = [0 for i in range(n)]
        even = 0
        odd = 1
        for i in nums:
            if i % 2 == 0:
                res[even] = i
                even = even + 2
            else:
                res[odd] = i
                odd = odd + 2

        return res