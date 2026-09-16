# https://leetcode.cn/problems/number-of-sets-of-k-non-overlapping-line-segments/

class Solution:
    def numberOfSets(self, n: int, k: int) -> int:
        mod = int(1e9) + 7
        dp = [[0 for _ in range(k+1)] for _ in range(n+1)]
        for size in range(1, n+1):
            dp[size][0] = 1
        for cnt in range(1, k+1):
            presum = 0
            for size in range(cnt+1, n+1):
                presum = (presum + dp[size-1][cnt-1]) % mod
                dp[size][cnt] = (dp[size-1][cnt] + presum) % mod
        return dp[n][k]