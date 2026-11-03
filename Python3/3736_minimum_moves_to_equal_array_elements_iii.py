# https://leetcode.cn/problems/minimum-moves-to-equal-array-elements-iii/

class Solution:
    def minMoves(self, nums: list[int]) -> int:
        return max(nums) * len(nums) - sum(nums)