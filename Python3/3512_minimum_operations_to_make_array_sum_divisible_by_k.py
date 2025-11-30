# https://leetcode.cn/problems/minimum-operations-to-make-array-sum-divisible-by-k/

class Solution:
    def minOperations(self, nums: list[int], k: int) -> int:
        return sum(nums) % k