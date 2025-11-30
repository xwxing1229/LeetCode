# https://leetcode.cn/problems/make-sum-divisible-by-p/

from collections import defaultdict

class Solution:
    def minSubarray(self, nums: list[int], p: int) -> int:
        rem = sum(nums) % p
        if rem == 0:
            return 0
        
        # Given sum_i, we want to find sum_j with the maximum j s.t.
        # j <= i and (sum_i - sum_j) % p = sum(nums) % p.
        # Then the subarray to be removed is [nums[j+1], ..., nums[i]].
        res, s = len(nums), 0
        record = defaultdict(int)
        record[0] = -1
        for i, num in enumerate(nums):
            s = (s + num) % p
            record[s] = i
            tar = (s - rem + p) % p
            if tar in record:
                res = min(res, i-record[tar])
            
        return res if res < len(nums) else -1