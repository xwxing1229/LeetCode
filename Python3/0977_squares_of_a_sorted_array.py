# https://leetcode-cn.com/problems/squares-of-a-sorted-array/
class Solution:
    def sortedSquares(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[int]
        """

        n = len(nums)
        i = n
        for idx in range(n):
            if nums[idx] >= 0:
                i = idx
                break
        j = i - 1

        res = [0 for _ in range(n)]
        idx = 0
        while j > -1 and i < n:
            pos, neg = nums[i], nums[j]
            if pos + neg <= 0:
                res[idx] = pos * pos
                i = i + 1
            else:
                res[idx] = neg * neg
                j = j - 1
            idx = idx + 1

        if j <= -1: # there are only nonnegtive numbers left
            while i < n:
                res[idx] = nums[i] * nums[i]
                i = i + 1
                idx = idx + 1
        else: # there are only negative numbers left
            while j > -1:
                res[idx] = nums[j] * nums[j]
                j = j - 1
                idx = idx + 1
                
        return res