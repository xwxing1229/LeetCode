# https://leetcode.cn/problems/maximum-k-to-sort-a-permutation/

class Solution:
    def sortPermutation(self, nums: list[int]) -> int:
        if nums[0] != 0:
            return 0

        res = -1
        for i, num in enumerate(nums):
            if num != i:
                res &= num
        return max(res, 0)