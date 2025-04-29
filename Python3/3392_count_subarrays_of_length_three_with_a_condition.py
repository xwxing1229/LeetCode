# https://leetcode.cn/problems/count-subarrays-of-length-three-with-a-condition/

class Solution:
    def countSubarrays(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        res = 0
        for i in range(1, len(nums)-1):
            if (nums[i-1] + nums[i+1]) * 2 == nums[i]:
                res += 1
        return res