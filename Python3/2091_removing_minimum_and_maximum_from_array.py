# https://leetcode.cn/problems/removing-minimum-and-maximum-from-array/

class Solution:
    def minimumDeletions(self, nums: list[int]) -> int:
        n = len(nums)
        idx_mn, idx_mx = 0, 0
        for i, num in enumerate(nums):
            if num < nums[idx_mn]:
                idx_mn = i
            if num > nums[idx_mx]:
                idx_mx = i
        left = min(idx_mn, idx_mx)
        right = max(idx_mn, idx_mx)
        return min(
            right + 1,
            n - left,
            left + 1 + n - right
        )