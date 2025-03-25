# https://leetcode.cn/problems/maximum-or/

class Solution:
    def maximumOr(self, nums, k):
        """
        Inputs:
            nums: list[int]
            k: int
        Outputs:
            res: int
        """
        n = len(nums)
        rightor = [0 for _ in range(n)]
        for i in range(n-2, -1, -1):
            rightor[i] = rightor[i+1] | nums[i+1]
        
        res = 0
        leftor = 0
        for i in range(n):
            tmp = leftor | (nums[i] << k) | rightor[i]
            if tmp > res:
                res = tmp
            leftor |= nums[i]
        return res