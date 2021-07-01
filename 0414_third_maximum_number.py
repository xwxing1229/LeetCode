# https://leetcode-cn.com/problems/third-maximum-number/

class Solution:
    def thirdMax(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        nums_new = list(set(nums))
        n = len(nums_new)
        if n < 3:
            return max(nums_new)

        nums_new.sort()
        nums_new.pop()
        nums_new.pop()
        return nums_new[n-3]