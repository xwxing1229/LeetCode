# https://leetcode.cn/problems/minimum-deletions-to-make-array-beautiful/

class Solution:
    def minDeletion(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        res = 0
        i, n = 0, len(nums)
        while i < n:
            print(i)
            cur = nums[i]
            i += 1
            while i < n and nums[i] == cur:
                i += 1
                res += 1
            if i == n:
                res += 1
            i += 1
        return res