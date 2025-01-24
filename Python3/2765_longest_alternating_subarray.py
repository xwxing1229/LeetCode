# https://leetcode.cn/problems/longest-alternating-subarray/

class Solution:
    def alternatingSubarray(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        res = 0
        i, n, diff = 0, len(nums), 1
        while i < n:
            start = i
            while i+1 < n and nums[i+1] - nums[i] == diff:
                i += 1
                diff *= (-1)
            res = max(res, i-start+1)
            if (i+1 < n and nums[i+1] - nums[i] != 1) or i == n-1:
                i += 1
            diff = 1
        return res if res > 1 else -1