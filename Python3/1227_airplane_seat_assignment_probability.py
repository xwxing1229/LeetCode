# https://leetcode.cn/problems/airplane-seat-assignment-probability/

class Solution:
    def nthPersonGetsNthSeat(self, n: int) -> float:
        # dp[i]: when there are i people in total, the probability that the i-th
        #        people can take his own seat
        # i = 1: 1
        # i = 2: 1/2
        # i = 3: 1/3 + 1/3 * dp[2]
        # i = 4: 1/4 + 1/4 * dp[3] + 1/4 * dp[2]
        # i = k: 1/k + 1/k * dp[k-1] + ... + 1/k * dp[2]
        dp = [1 for _ in range(n+1)]
        if n >= 2:
            dp[2] = 0.5
        cumsum = 1.5
        for i in range(3, n+1):
            dp[i] = cumsum / i
            cumsum += dp[i]
        return dp[n]