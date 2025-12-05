# https://leetcode.cn/problems/count-partitions-with-even-sum-difference/

class Solution:
    def countPartitions(self, nums: list[int]) -> int:
        res = 0
        left, s = 0, sum(nums)
        for i in range(len(nums)-1):
            left += nums[i]
            right = s - left
            res += 1 - (max(left,right) - min(left,right)) % 2
        return res