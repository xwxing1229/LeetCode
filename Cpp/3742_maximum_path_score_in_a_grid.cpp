// https://leetcode.cn/problems/maximum-path-score-in-a-grid/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        // dp[i][j][c]: maximum score obtained at grid[i][j] with cost c
        // Optimize space complexity.
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        dp[0][0] = grid[0][0];
        for (int j = 1; j < n; ++j) {
            int cost = grid[0][j] == 0 ? 0 : 1;
            for (int c = cost; c <= min(j, k); ++c) {
                if (dp[j-1][c-cost] >= 0) {
                    dp[j][c] = max(dp[j][c], dp[j-1][c-cost] + grid[0][j]);
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            vector<vector<int>> dp_curr(n, vector<int>(k+1, -1));
            for (int j = 0; j < n; ++j) {
                int cost = grid[i][j] == 0 ? 0 : 1;
                for (int c = cost; c <= min(i+j, k); ++c) {
                    if (dp[j][c-cost] >= 0) {
                        dp_curr[j][c] = max(dp_curr[j][c], dp[j][c-cost] + grid[i][j]);
                    }
                    if (j > 0 && dp_curr[j-1][c-cost] >= 0) {
                        dp_curr[j][c] = max(dp_curr[j][c], dp_curr[j-1][c-cost] + grid[i][j]);
                    }
                }
            }
            dp = dp_curr;
        }
        int res = -1;
        for (int c = 0; c <= k; ++c) {
            res = max(res, dp[n-1][c]);
        }
        return res;

        
        // // dp[i][j][c]: maximum score obtained at grid[i][j] with cost c
        // int m = grid.size(), n = grid[0].size();
        // vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1, -1)));
        // dp[0][0][0] = grid[0][0];
        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         int cost = grid[i][j] == 0 ? 0 : 1;
        //         for (int c = cost; c <= min(i + j, k); ++c) {
        //             if (i > 0 && dp[i-1][j][c-cost] >= 0) {
        //                 dp[i][j][c] = max(dp[i][j][c], dp[i-1][j][c-cost] + grid[i][j]);
        //             }
        //             if (j > 0 && dp[i][j-1][c-cost] >= 0) {
        //                 dp[i][j][c] = max(dp[i][j][c], dp[i][j-1][c-cost] + grid[i][j]);
        //             }
        //         }
        //     }
        // }
        // int res = -1;
        // for (int c = 0; c <= k; ++c) {
        //     res = max(res, dp[m-1][n-1][c]);
        // }
        // return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {0,1},
        {1,2}
    };
    int k = 1;
    cout << sol.maxPathScore(grid, k) << '\n';
    return 0;
}