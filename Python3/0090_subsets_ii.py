# https://leetcode.cn/problems/subsets-ii/

class Solution:
    def subsetsWithDup(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[list[int]]
        """
        nums.sort()
        res = [[], [nums[0]]]
        add = 1
        for i in range(1, len(nums)):
            num = nums[i]
            n = len(res)
            if num != nums[i-1]:
                add = n
            for k in range(n-add, n):
                res.append(res[k] + [num])
        return res