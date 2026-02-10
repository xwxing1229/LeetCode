# https://leetcode.cn/problems/longest-balanced-subarray-i/

from collections import defaultdict

class Solution:
    def longestBalanced(self, nums: list[int]) -> int:
        res = 0
        n = len(nums)
        for i, num in enumerate(nums):
            cnt = defaultdict(int)
            cnt[num] += 1
            record = [0, 0]
            record[num % 2] += 1
            for j in range(i+1, n):
                cnt[nums[j]] += 1
                if cnt[nums[j]] < 2:
                    record[nums[j] % 2] += 1
                if record[0] == record[1]:
                    res = max(res, j-i+1)
        return res