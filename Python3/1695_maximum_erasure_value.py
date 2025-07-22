# https://leetcode.cn/problems/maximum-erasure-value/

class Solution:
    def maximumUniqueSubarray(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        res = 0
        left, tmp = 0, 0
        s = set()
        for i, num in enumerate(nums):
            while left < i and num in s:
                tmp -= nums[left]
                s.remove(nums[left])
                left += 1
            tmp += num
            s.add(num)
            res = max(res, tmp)
        return res