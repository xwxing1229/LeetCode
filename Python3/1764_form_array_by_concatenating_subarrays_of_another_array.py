# https://leetcode.cn/problems/form-array-by-concatenating-subarrays-of-another-array/

class Solution:
    def canChoose(self, groups, nums):
        """
        Inputs:
            groups: list[list[int]]
            nums: list[int]
        Outputs:
            res: bool
        """
        i, n = 0, len(nums)
        for group in groups:
            equal = False
            while i + len(group) <= n:
                if group == nums[i: i+len(group)]:
                    i += len(group)
                    equal = True
                    break
                i += 1
            if not equal:
                return False
        return True