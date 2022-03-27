# https://leetcode-cn.com/problems/smallest-range-ii/
class Solution:
    def smallestRangeII(self, nums, k):
        """
        Inputs:
            nums: list[int]
            k: int
        Outputs:
            res: int
        """

        nums.sort()
        n = len(nums)

        res = nums[n-1] - nums[0]
        for i in range(n-1):
            max_ = max(nums[i]+k, nums[n-1]-k)
            min_ = min(nums[0]+k, nums[i+1]-k)
            res = min(res, max_-min_)

        return res