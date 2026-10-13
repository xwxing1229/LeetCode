# https://leetcode.cn/problems/maximum-alternating-sum-of-squares/

class Solution:
    def maxAlternatingSum(self, nums: list[int]) -> int:
        res = 0
        vals = [abs(num) for num in nums]
        vals.sort()
        left, right = 0, len(vals)-1
        while left < right:
            res += vals[right] ** 2 - vals[left] ** 2
            left += 1
            right -= 1
        res += vals[left] ** 2 * (left == right)
        return res