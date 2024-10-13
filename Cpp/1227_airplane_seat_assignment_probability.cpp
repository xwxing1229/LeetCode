// https://leetcode.cn/problems/airplane-seat-assignment-probability/

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        // dp[i]: when there are i people in total, the probability that the i-th
        //        people can take his own seat
        // i = 1: 1
        // i = 2: 1/2
        // i = 3: 1/3 + 1/3 * dp[2]
        // i = 4: 1/4 + 1/4 * dp[3] + 1/4 * dp[2]
        // i = k: 1/k + 1/k * dp[k-1] + ... + 1/k * dp[2]
        vector<double> dp(n+1, 1);
        if (n >= 2) {
            dp[2] = 0.5;
        }
        double cumsum = 1.5;
        for (int i = 3; i <= n; ++i) {
            dp[i] = cumsum / i;
            cumsum += dp[i];
        }
        return dp[n];
    }
};
