# https://leetcode-cn.com/problems/maximum-product-of-three-numbers/
class Solution:
    def maximumProduct(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        nums.sort()
        n = len(nums)
        tmp1 = nums[n-1] * nums[n-2] * nums[n-3]
        tmp2 = nums[0] * nums[1] * nums[n-1]

        return max(tmp1, tmp2)