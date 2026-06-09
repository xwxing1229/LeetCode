# https://leetcode.cn/problems/maximum-total-subarray-value-i/

class Solution:
    def maxTotalValue(self, nums: list[int], k: int) -> int:
        return k * (max(nums) - min(nums))