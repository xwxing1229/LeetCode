# https://leetcode.cn/problems/number-of-distinct-averages/

class Solution:
    def distinctAverages(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        s = set()
        nums.sort()
        n = len(nums)
        for i in range(n//2):
            s.add(nums[i] + nums[n-1-i])
        return len(s)