# https://leetcode.cn/problems/adjacent-increasing-subarrays-detection-ii

class Solution:
    def maxIncreasingSubarrays(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        res = 1
        pre, cur = 0, 1
        for i in range(1, len(nums)):
            if nums[i] > nums[i-1]:
                cur += 1
                res = max(res, cur//2, min(pre, cur))
            else:
                res = max(res, cur//2, min(pre, cur))
                pre = cur
                cur = 1
        return res