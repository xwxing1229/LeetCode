# https://leetcode.cn/problems/tuple-with-same-product/

class Solution:
    def tupleSameProduct(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        counts = dict()
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                prod = nums[i] * nums[j]
                counts[prod] = counts.get(prod, 0) + 1
        res = 0
        for v in counts.values():
            if v >= 2:
                res += v * (v-1)
        return res * 4