# https://leetcode.cn/problems/longest-even-odd-subarray-with-threshold/

class Solution:
    def longestAlternatingSubarray(self, nums, threshold):
        """
        Inputs:
            nums: list[int]
            threshold: int
        Outputs:
            res: int
        """
        res = 0
        i, n = 0, len(nums)
        while i < n:
            while i < n and (nums[i] % 2 != 0 or nums[i] > threshold):
                i += 1
            if i >= n:
                break
            left = i
            i += 1
            while i < n and nums[i] % 2 != nums[i-1] % 2 and nums[i] <= threshold:
                i += 1
            res = max(res, i-left)
        return res