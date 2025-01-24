# https://leetcode.cn/problems/happy-students/

class Solution:
    def countWays(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        nums.sort()
        res = 1 if nums[0] == 0 else 2
        for i in range(1, len(nums)):
            if i > nums[i-1] and i < nums[i]:
                res += 1
        return res