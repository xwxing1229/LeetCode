# https://leetcode.cn/problems/check-if-array-is-good/

class Solution:
    def isGood(self, nums: list[int]) -> bool:
        nums.sort()
        n = nums[-1]
        if len(nums) != n+1 or nums[-2] != n:
            return False
        for i in range(n):
            if nums[i] != i+1:
                return False
        return True