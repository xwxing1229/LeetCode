# https://leetcode.cn/problems/smallest-missing-multiple-of-k/

class Solution:
    def missingMultiple(self, nums: list[int], k: int) -> int:
        s = set(nums)
        for x in range(k, max(nums)+k+1, k):
            if x not in s:
                return x
        return -1