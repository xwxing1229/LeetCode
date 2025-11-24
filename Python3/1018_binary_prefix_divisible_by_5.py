# https://leetcode.cn/problems/binary-prefix-divisible-by-5/

class Solution:
    def prefixesDivBy5(self, nums: list[int]) -> list[bool]:
        n = len(nums)
        res = [False for _ in range(n)]
        value = 0
        for i, num in enumerate(nums):
            value = (value << 1 | num) % 5
            res[i] = (value == 0)
        return res