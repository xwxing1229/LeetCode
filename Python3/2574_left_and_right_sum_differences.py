# https://leetcode.cn/problems/left-and-right-sum-differences/

class Solution:
    def leftRightDifference(self, nums: list[int]) -> list[int]:
        n = len(nums)
        right = [0 for _ in range(n)]
        for i in range(n-1, 0, -1):
            right[i-1] = right[i] + nums[i]
        res = [0 for _ in range(n)]
        left = 0
        for i, num in enumerate(nums):
            res[i] = abs(left - right[i])
            left += num
        return res