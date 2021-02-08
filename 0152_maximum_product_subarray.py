# https://leetcode-cn.com/problems/maximum-product-subarray/

class Solution:
    def maxProduct(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        n = len(nums)
        dp_max = [0 for i in range(n)]
        dp_min = [0 for i in range(n)]
        dp_max[0] = nums[0]
        dp_min[0] = nums[0]

        for i in range(1,n):
            dp_max[i] = max(nums[i], dp_max[i-1]*nums[i], dp_min[i-1]*nums[i])
            dp_min[i] = min(nums[i], dp_max[i-1]*nums[i], dp_min[i-1]*nums[i])

        res = max(dp_max)
        return res