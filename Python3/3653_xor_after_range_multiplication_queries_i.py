# https://leetcode.cn/problems/xor-after-range-multiplication-queries-i/

class Solution:
    def xorAfterQueries(self, nums: list[int], queries: list[list[int]]) -> int:
        mod = int(1e9) + 7
        for l, r, k, v in queries:
            idx = l
            while idx <= r:
                nums[idx] = (nums[idx] * v) % mod
                idx += k
        res = 0
        for num in nums:
            res ^= num
        return res