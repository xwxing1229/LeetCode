# https://leetcode.cn/problems/smallest-stable-index-i/

class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        sufmin = [nums[-1] for _ in range(len(nums))]
        for i in range(len(nums)-2, -1, -1):
            sufmin[i] = min(sufmin[i+1], nums[i])
        premax = nums[0]
        for i, num in enumerate(nums):
            premax = max(premax, num)
            if premax - sufmin[i] <= k:
                return i
        return -1