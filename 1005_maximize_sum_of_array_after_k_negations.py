# https://leetcode-cn.com/problems/maximize-sum-of-array-after-k-negations/
class Solution:
    def largestSumAfterKNegations(self, nums, k):
        """
        Inputs:
            nums: list[int]
            k: int
        Outputs:
            res: int
        """

        nums.sort()
        n = len(nums)
        idx = 0
        while idx < n and nums[idx] < 0 and k > 0:
            nums[idx] = -nums[idx]
            idx = idx + 1
            k = k - 1

        res = sum(nums)
        if k > 0 and k % 2 == 1:
            res = res - 2 * min(nums[min(idx,n-1)], nums[max(idx-1,0)])

        return res