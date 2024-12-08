// https://leetcode.cn/problems/knight-probability-in-chessboard/

class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<pair<int,int>> dirs = {{1,2}, {1,-2}, {-1,2}, {-1,-2}, {2,1}, {2,-1}, {-2,1}, {-2,-1}};
        vector<vector<vector<double>>> dp(k+1, vector<vector<double>>(n+4, vector<double>(n+4, 0)));
        for (int i = 2; i < n+2; ++i) {
            for (int j = 2; j < n+2; ++j) {
                dp[0][i][j] = 1;
            }
        }
        for (int step = 1; step <= k; ++step) {
            for (int i = 2; i < n+2; ++i) {
                for (int j = 2; j < n+2; ++j) {
                    double p = 0;
                    for (auto &d: dirs) {
                        p += dp[step-1][i-d.first][j-d.second];
                    }
                    dp[step][i][j] = p / 8;
                }
            }
        }
        return dp[k][row+2][column+2];
    }
};
