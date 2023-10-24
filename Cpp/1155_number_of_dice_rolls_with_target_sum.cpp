// https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum/

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1000000007;
        vector<vector<int>> dp(n, (vector<int>)(target+1));
        for (int j = 1; j <= min(k,target); ++j) {
            dp[0][j] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= target; ++j) {
                for (int roll = 1; roll <= min(j,k); ++roll) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-roll]) % mod;
                }
            }
        }
        return dp[n-1][target];
    }
};
