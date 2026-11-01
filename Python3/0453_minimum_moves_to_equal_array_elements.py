# https://leetcode.cn/problems/minimum-moves-to-equal-array-elements/

class Solution:
    def minMoves(self, nums: list[int]) -> int:
        # Increasing n-1 elements by 1 works similarly as decreasing 1 element by 1.
        return sum(nums) - min(nums) * len(nums)