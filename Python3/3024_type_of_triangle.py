# https://leetcode.cn/problems/type-of-triangle/

class Solution:
    def triangleType(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: str
        """
        nums.sort()
        if nums[0] + nums[1] <= nums[2]:
            return "none"
        elif nums[0] == nums[2]:
            return "equilateral"
        elif nums[0] == nums[1] or nums[2] == nums[1]:
            return "isosceles"
        else:
            return "scalene"