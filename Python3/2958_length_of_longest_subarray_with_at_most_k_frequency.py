# https://leetcode.cn/problems/length-of-longest-subarray-with-at-most-k-frequency/

from collections import defaultdict

class Solution:
    def maxSubarrayLength(self, nums: list[int], k: int) -> int:
        res = 0
        count = defaultdict(int)
        left = 0
        for i, num in enumerate(nums):
            count[num] += 1
            while count[num] > k:
                count[nums[left]] -= 1
                left += 1
            res = max(res, i - left + 1)
        return res