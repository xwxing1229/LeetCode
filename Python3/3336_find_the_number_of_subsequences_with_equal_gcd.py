# https://leetcode.cn/problems/find-the-number-of-subsequences-with-equal-gcd/

from math import gcd

class Solution:
    def subsequencePairCount(self, nums: list[int]) -> int:
        mod = int(1e9) + 7
        max_ = max(nums)
        dp = [[0 for _ in range(max_+1)] for _ in range(max_+1)]
        dp[0][0] = 1
        for num in nums:
            dp_next = [[0 for _ in range(max_+1)] for _ in range(max_+1)]

            for j in range(max_+1):
                gcd1 = gcd(j, num)
                for k in range(max_+1):
                    if dp[j][k] == 0:
                        continue
                    gcd2 = gcd(k, num)
                    dp_next[j][k] = (dp_next[j][k] + dp[j][k]) % mod
                    dp_next[gcd1][k] = (dp_next[gcd1][k] + dp[j][k]) % mod
                    dp_next[j][gcd2] = (dp_next[j][gcd2] + dp[j][k]) % mod
            
            dp = dp_next
        
        res = 0
        for j in range(1, max_+1):
            res = (res + dp[j][j]) % mod
        return res