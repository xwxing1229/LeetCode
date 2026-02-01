# https://leetcode.cn/problems/divide-an-array-into-subarrays-with-minimum-cost-i/

class Solution:
    def minimumCost(self, nums: list[int]) -> int:
        res = nums[0]
        min_1, min_2 = min(nums[1], nums[2]), max(nums[1], nums[2])
        for i in range(3, len(nums)):
            if nums[i] <= min_1:
                min_2 = min_1
                min_1 = nums[i]
            elif nums[i] < min_2:
                min_2 = nums[i]
        res += min_1 + min_2
        return res