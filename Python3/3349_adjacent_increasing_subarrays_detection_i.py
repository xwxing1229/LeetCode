# https://leetcode.cn/problems/adjacent-increasing-subarrays-detection-i/

class Solution:
    def hasIncreasingSubarrays(self, nums, k):
        """
        Inputs:
            nums: list[int]
            k: int
        Outputs:
            res: bool
        """
        n = len(nums)
        incr = [1 for _ in range(n)]
        for i in range(1, n):
            if nums[i] > nums[i-1]:
                incr[i] = incr[i-1] + 1
        for i in range(k-1, n-k):
            if incr[i] >= k and incr[i+k] >= k:
                return True
        return False