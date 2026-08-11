# https://leetcode.cn/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/

class Solution:
    def missingInteger(self, nums: list[int]) -> int:
        res = nums[0]
        for i in range(1, len(nums)):
            if nums[i] - nums[i-1] != 1:
                break
            res += nums[i]
        s = set(nums)
        while res in s:
            res += 1
        return res