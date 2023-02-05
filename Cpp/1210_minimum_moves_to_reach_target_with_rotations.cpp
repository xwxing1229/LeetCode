// https://leetcode.cn/problems/minimum-moves-to-reach-target-with-rotations/

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int invalid = INT_MAX / 2;
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, invalid)));
        dp[0][0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                bool can_horizontal = (j + 1 < n && grid[i][j] == 0 && grid[i][j+1] == 0);
                bool can_vertical = (i + 1 < n && grid[i][j] == 0 && grid[i+1][j] == 0);

                if (i - 1 >= 0 && can_horizontal) {
                    dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][0] + 1);
                }
                if (j - 1 >= 0 && can_horizontal) {
                    dp[i][j][0] = min(dp[i][j][0], dp[i][j-1][0] + 1);
                }
                if (i - 1 >= 0 && can_vertical) {
                    dp[i][j][1] = min(dp[i][j][1], dp[i-1][j][1] + 1);
                }
                if (j - 1 >= 0 && can_vertical) {
                    dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][1] + 1);
                }

                if (can_horizontal && can_vertical && grid[i+1][j+1] == 0) {
                    dp[i][j][0] = min(dp[i][j][0], dp[i][j][1] + 1);
                    dp[i][j][1] = min(dp[i][j][1], dp[i][j][0] + 1);
                }
            }
        }
        if (dp[n-1][n-2][0] == invalid) return -1;
        else return dp[n-1][n-2][0];
    }
};
