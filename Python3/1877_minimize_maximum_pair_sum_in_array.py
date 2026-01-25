# https://leetcode.cn/problems/minimize-maximum-pair-sum-in-array/

class Solution:
    def minPairSum(self, nums: list[int]) -> int:
        nums.sort()
        res = nums[0] + nums[-1]
        n = len(nums)
        for i in range(n//2):
            res = max(res, nums[i] + nums[n-1-i])
        return res