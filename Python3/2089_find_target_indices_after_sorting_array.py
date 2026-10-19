# https://leetcode.cn/problems/find-target-indices-after-sorting-array/

class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        res = []
        nums.sort()
        for i, num in enumerate(nums):
            if num == target:
                res.append(i)
        return res