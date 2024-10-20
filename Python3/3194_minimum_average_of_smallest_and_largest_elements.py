# https://leetcode.cn/problems/minimum-average-of-smallest-and-largest-elements/

class Solution:
    def minimumAverage(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: float
        """
        nums.sort()
        left, right = 0, len(nums)-1
        res = (nums[left] + nums[right]) / 2
        while left < right:
            res = min(res, (nums[left] + nums[right]) / 2)
            left += 1
            right -= 1
        return res