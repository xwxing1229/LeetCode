# https://leetcode.cn/problems/visit-array-positions-to-maximize-score/

class Solution:
    def maxScore(self, nums, x):
        """
        Inputs:
            nums: list[int]
            x: int
        Outputs:
            res: int
        """
        odd, even = nums[0], -1000000
        if nums[0] % 2 == 0:
            odd, even = -1000000, nums[0]
        for i in range(1, len(nums)):
            num = nums[i]
            if num % 2 == 0:
                even = max(even + num, odd + num - x)
            else:
                odd = max(odd + num, even + num - x)
            
        return max(odd, even)