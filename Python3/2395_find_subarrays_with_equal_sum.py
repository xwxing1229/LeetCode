# https://leetcode.cn/problems/find-subarrays-with-equal-sum/

class Solution:
    def findSubarrays(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: bool
        """
        check = set()
        for i in range(1, len(nums)):
            s = nums[i-1] + nums[i]
            if s in check:
                return True
            check.add(s)
        return False
