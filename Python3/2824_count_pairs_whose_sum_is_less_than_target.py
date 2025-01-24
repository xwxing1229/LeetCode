# https://leetcode.cn/problems/count-pairs-whose-sum-is-less-than-target/

class Solution:
    def countPairs(self, nums, target):
        """
        Inputs:
            nums: list[int]
            target: int
        Outputs:
            res: int
        """
        res = 0
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if nums[i] + nums[j] < target:
                    res += 1
        return res