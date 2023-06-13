# https://leetcode.cn/problems/number-of-unequal-triplets-in-array/

class Solution:
    def unequalTriplets(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        res = 0
        for i in range(len(nums)):
            num1 = nums[i]
            for j in range(i+1, len(nums)):
                num2 = nums[j]
                if num1 == num2:
                    continue
                for k in range(j+1, len(nums)):
                    if nums[k] != num1 and nums[k] != num2:
                        res += 1
        return res