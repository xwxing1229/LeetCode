# https://leetcode.cn/problems/maximize-score-after-n-operations/

class Solution:
    def maxScore(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        n = len(nums)
        g = [[0 for j in range(n)] for i in range(n)]
        for i in range(n):
            for j in range(i+1, n):
                g[i][j] = gcd(nums[i], nums[j])
        
        dp = [0 for _ in range(1 << n)]
        for k in range(1 << n):
            cnt = k.bit_count()
            if cnt % 2 == 0:
                for i in range(n):
                    if (k >> i) & 1:
                        for j in range(i+1, n):
                            if (k >> j) & 1:
                                dp[k] = max(dp[k], dp[k^(1<<i)^(1<<j)] + cnt // 2 * g[i][j])
        return dp[-1]