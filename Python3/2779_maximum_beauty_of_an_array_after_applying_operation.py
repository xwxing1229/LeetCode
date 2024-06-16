# https://leetcode.cn/problems/maximum-beauty-of-an-array-after-applying-operation/

class Solution:
    def maximumBeauty(self, nums, k):
        """
        Inputs:
            nums: list[int]
            k: int
        Outputs:
            res: int
        """
        nums.sort()
        left, diff = 0, 2 * k
        res = 1
        for right in range(len(nums)):
            while nums[right] - nums[left] > diff:
                left += 1
            res = max(res, right-left+1)
        return res