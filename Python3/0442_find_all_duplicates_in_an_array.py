# https://leetcode.cn/problems/find-all-duplicates-in-an-array/

class Solution:
    def findDuplicates(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[int]
        """

        res = []
        for i in range(len(nums)):
            k = abs(nums[i])
            if nums[k-1] > 0:
                nums[k-1] = -nums[k-1]
            else:
                res.append(k)
        return res
