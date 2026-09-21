# https://leetcode.cn/problems/find-x-value-of-array-i/

class Solution:
    def resultArray(self, nums: list[int], k: int) -> list[int]:
        res = [0 for _ in range(k)]
        n = len(nums)
        dp = [[0 for _ in range(k)] for _ in range(n+1)]
        for i, num in enumerate(nums):
            dp[i+1][num%k] = 1
            for mod, cnt in enumerate(dp[i]):
                dp[i+1][num*mod%k] += cnt
            for mod, cnt in enumerate(dp[i+1]):
                res[mod] += cnt
        return res