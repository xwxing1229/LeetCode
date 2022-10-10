// https://leetcode.cn/problems/frog-jump/

class Solution {
public:
    bool canCross(vector<int>& stones) {
        // dp[i][k] = 1: can reach the ith stone with a jump of k units from a previous stone
        // dp[i][k] = 0: cannot reach the ith stone with a jump of k units from a previous stone
        int n = stones.size();
        vector<vector<int>> dp(n, (vector<int>)(n+1));
        dp[0][0] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = i-1; j >= 0; --j) {
                int k = stones[i] - stones[j];
                if (k > j+1) {
                    continue;
                }
                if (dp[j][k-1] || dp[j][k] || dp[j][k+1]) {
                    dp[i][k] = 1;
                    if (i == n-1) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
