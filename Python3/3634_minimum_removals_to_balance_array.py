# https://leetcode.cn/problems/minimum-removals-to-balance-array/

class Solution:
    def minRemoval(self, nums: list[int], k: int) -> int:
        nums.sort()
        max_len = 0
        n = len(nums)
        right = 0
        for left in range(n):
            while right < n and nums[right] / nums[left] <= k:
                right += 1
            max_len = max(max_len, right-left)
        return n - max_len