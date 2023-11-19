# https://leetcode.cn/problems/maximum-sum-of-3-non-overlapping-subarrays/

class Solution:
    def maxSumOfThreeSubarrays(self, nums, k):
        """
        Inputs:
            nums: list[int]
            k: int
        Outputs:
            res: list[int]
        """
        res = []
        sum1, max_sum1, max_sum1_idx = 0, 0, 0
        sum2, max_sum12, max_sum12_idx = 0, 0, []
        sum3, max_sum123 = 0, 0
        for i in range(2*k, len(nums)):
            sum1 += nums[i-k-k]
            sum2 += nums[i-k]
            sum3 += nums[i]
            if i >= 3*k-1:
                if sum1 > max_sum1:
                    max_sum1 = sum1
                    max_sum1_idx = i-k-k-k+1

                if max_sum1 + sum2 > max_sum12:
                    max_sum12 = max_sum1 + sum2
                    max_sum12_idx = [max_sum1_idx, i-k-k+1]

                if max_sum12 + sum3 > max_sum123:
                    max_sum123 = max_sum12 + sum3
                    res = [max_sum12_idx[0], max_sum12_idx[1], i-k+1]

                sum1 -= nums[i-k-k-k+1]
                sum2 -= nums[i-k-k+1]
                sum3 -= nums[i-k+1]
        return res