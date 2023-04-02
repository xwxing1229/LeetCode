// https://leetcode.cn/problems/minimum-score-triangulation-of-polygon/

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = n-2; i >= 0; --i) {
            dp[i][i+1] = 0;
            for (int j = i + 2; j < n; ++j) {
                for (int k = i+1; k < j; ++k) {
                    int tmp = dp[i][k] + values[i]*values[k]*values[j] + dp[k][j];
                    if (dp[i][j] < 0) {
                        dp[i][j] = tmp;
                    }
                    else {
                        dp[i][j] = min(dp[i][j], tmp);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};
