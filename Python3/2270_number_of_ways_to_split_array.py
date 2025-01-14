# https://leetcode.cn/problems/number-of-ways-to-split-array/

class Solution:
    def waysToSplitArray(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        cumsum = [0 for _ in range(len(nums)+1)]
        for i, num in enumerate(nums):
            cumsum[i+1] = cumsum[i] + num
            
        res = 0 
        for i in range(len(nums)-1):
            if cumsum[i+1] >= cumsum[-1] - cumsum[i+1]:
                res += 1
        return res