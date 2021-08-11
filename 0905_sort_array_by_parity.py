# https://leetcode-cn.com/problems/sort-array-by-parity/
class Solution:
    def sortArrayByParity(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[int]
        """

        l = 0
        r = len(nums) - 1
        while l < r:
            cur = nums[l]
            if cur % 2 != 0:
                tmp = nums[r]
                nums[r] = cur
                nums[l] = tmp
                r = r - 1
            else:
                l = l + 1
        return nums