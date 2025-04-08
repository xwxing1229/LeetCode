# https://leetcode.cn/problems/maximum-value-of-an-ordered-triplet-ii/

class Solution:
    def maximumTripletValue(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        n = len(nums)
        right_max = [0 for _ in range(n)]
        for i in range(n-2, -1, -1):
            right_max[i] = max(right_max[i+1], nums[i+1])
            
        res, left_max = 0, nums[0]
        for i in range(1, n-1):
            res = max(res, (left_max - nums[i]) * right_max[i])
            left_max = max(left_max, nums[i])
        return res * (res > 0)