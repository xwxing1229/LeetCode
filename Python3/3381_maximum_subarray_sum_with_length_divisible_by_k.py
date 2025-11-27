# https://leetcode.cn/problems/maximum-subarray-sum-with-length-divisible-by-k/

class Solution:
    def maxSubarraySum(self, nums: list[int], k: int) -> int:
        n = len(nums)
        cumsum = [0 for _ in range(n+1)]
        for i, num in enumerate(nums):
            cumsum[i+1] = cumsum[i] + num

        res = cumsum[k]
        # min_left[j] = min(sum(nums[0], ..., nums[i])) with (i - j) % k = 0.
        min_left = [cumsum[i+1] for i in range(k)]
        min_left[k-1] = min(0, min_left[k-1])
        for i in range(k, n):
            match = i % k
            res = max(res, cumsum[i+1] - min_left[match])
            min_left[match] = min(min_left[match], cumsum[i+1])
        return res