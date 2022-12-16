# https://leetcode.cn/problems/minimum-elements-to-add-to-form-a-given-sum/

class Solution:
    def minElements(self, nums, limit, goal):
        """
        Inputs:
            nums: list[int]
            limit: int
            goal: int
        Outputs:
            res: int
        """
        diff = abs(sum(nums) - goal)
        res = (diff + limit - 1) // limit
        return res