# https://leetcode.cn/problems/minimum-moves-to-equal-array-elements-ii/

class Solution:
    def minMoves2(self, nums: list[int]) -> int:
        # After sorting, let all numbers equal nums[k].
        nums.sort()
        n = len(nums)
        k = (n - 1) // 2
        return sum(nums[k:]) - sum(nums[:k]) - (n-2*k) * nums[k]