// https://leetcode.cn/problems/selling-pieces-of-wood/

class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<long long>> dp(m+1, vector<long long>(n+1, 0));
        for (auto &p: prices) {
            dp[p[0]][p[1]] = p[2];
        }
        for (int row = 1; row <= m; ++row) {
            for (int col = 1; col <= n; ++col) {
                for (int i = 1; i < row; ++i) {
                    dp[row][col] = max(dp[row][col], dp[i][col] + dp[row-i][col]);
                }
                for (int j = 1; j < col; ++j) {
                    dp[row][col] = max(dp[row][col], dp[row][j] + dp[row][col-j]);
                }
            }
        }
        return dp[m][n];
    }
};
