// https://leetcode.cn/problems/minimum-difficulty-of-a-job-schedule/

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1;

        // dp[i][j]: minimum difficulty until the ith day with the jth jobs done
        // dp[i][j] = min_{k=i-1, ..., j-1} (dp[i-1][k] + f(k+1, j)),
        // where f(k,j) = max(jobDifficulty[k], ..., jobDifficulty[j]).
        vector<vector<int>> f(n, vector<int>(n, 0));
        for (int k = 0; k < n; ++k) {
            f[k][k] = jobDifficulty[k];
            for (int j = k+1; j < n; ++j) {
                f[k][j] = max(f[k][j-1], jobDifficulty[j]);
            }
        }
        vector<vector<int>> dp(d, vector<int>(n, 0));
        for (int j = 0; j < n; ++j) {
            dp[0][j] = f[0][j];
        }
        for (int i = 1; i < d; ++i) {
            for (int j = i; j < n; ++j) {
                dp[i][j] = dp[i-1][i-1] + f[i][j];
                for (int k = i-1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + f[k+1][j]);
                }
            }
        }
        return dp[d-1][n-1];
    }
};
