# https://leetcode.cn/problems/single-number-ii/

class Solution:
    def singleNumber(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        res = 0
        for i in range(32):
            total = 0
            for num in nums:
                total = total + ((num >> i) & 1)

            if total % 3 == 1:
                if i == 31:
                    res = res - (1 << i)
                else:
                    res = res | (1 << i)
        return res
