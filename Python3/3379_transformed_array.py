# https://leetcode.cn/problems/transformed-array/

class Solution:
    def constructTransformedArray(self, nums: list[int]) -> list[int]:
        n = len(nums)
        res = [0 for _ in range(n)]
        for i, num in enumerate(nums):
            idx = (i + num) % n
            res[i] = nums[idx]
        return res