# https://leetcode.cn/problems/count-alternating-subarrays/

class Solution:
    def countAlternatingSubarrays(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        nums.append(nums[-1])
        res = 0
        start = 0
        for i in range(1, len(nums)):
            if nums[i] != nums[i-1]:
                continue
            n = i - start
            res += (1 + n) * n // 2
            start = i
        return res