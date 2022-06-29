# https://leetcode.cn/problems/maximum-product-subarray/

class Solution:
    def maxProduct(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

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
        """

        res = nums[0]
        tmp_max = nums[0]
        tmp_min = nums[0]
        for i in range(1, len(nums)):
            tmp = max(tmp_max*nums[i], max(tmp_min*nums[i], nums[i]))
            tmp_min = min(tmp_max*nums[i], min(tmp_min*nums[i], nums[i]))
            tmp_max = tmp
            res = max(res, tmp_max)
        return res