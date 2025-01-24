# https://leetcode.cn/problems/find-the-maximum-number-of-marked-indices/

class Solution:
    def maxNumOfMarkedIndices(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        nums.sort()
        res = 0
        n, j = len(nums), len(nums)//2
        for i in range(n//2):
            val = 2 * nums[i]
            while j < n and val > nums[j]:
                j += 1
            if j < n:
                res += 2
                j += 1
            else:
                break
        return res