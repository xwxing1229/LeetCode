# https://leetcode.cn/problems/minimum-number-game/

class Solution:
    def numberGame(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[int]
        """
        nums.sort()
        res = [0 for _ in range(len(nums))]
        for i in range(0, len(nums), 2):
            res[i] = nums[i+1]
            res[i+1] = nums[i]
        return res