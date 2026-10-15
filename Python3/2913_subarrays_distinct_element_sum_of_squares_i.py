# https://leetcode.cn/problems/subarrays-distinct-element-sum-of-squares-i/

class Solution:
    def sumCounts(self, nums: list[int]) -> int:
        res = 0
        n = len(nums)
        for i in range(n):
            s = set()
            for j in range(i, n):
                s.add(nums[j])
                res += len(s) * len(s)
        return res