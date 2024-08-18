# https://leetcode.cn/problems/maximum-number-of-operations-with-the-same-score-i/

class Solution:
    def maxOperations(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        pre = nums[0] + nums[1]
        res = 1
        for i in range(2, len(nums)-1, 2):
            if nums[i] + nums[i+1] == pre:
                res += 1
            else:
                break
        return res