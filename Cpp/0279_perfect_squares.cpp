// https://leetcode.cn/problems/perfect-squares/

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int tmp = dp[i-1];
            for (int j = 1; j <= sqrt(i); ++j) {
                tmp = min(tmp, dp[i-j*j]);
            }
            dp[i] = 1 + tmp;
        }
        return dp[n];
    }
};
