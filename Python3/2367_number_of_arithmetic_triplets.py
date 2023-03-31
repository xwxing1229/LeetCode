# https://leetcode.cn/problems/number-of-arithmetic-triplets/

class Solution:
    def arithmeticTriplets(self, nums, diff):
        """
        Inputs:
            nums: list[int]
            diff: int
        Outputs:
            res: int
        """
        s = set(nums)
        res = 0
        for num in nums:
            if num + diff in s and num + diff + diff in s:
                res += 1
        return res