# https://leetcode.cn/problems/make-array-zero-by-subtracting-equal-amounts/

class Solution:
    def minimumOperations(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        s = set()
        for num in nums:
            if num > 0:
                s.add(num)
        return len(s)