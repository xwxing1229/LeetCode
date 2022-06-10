// https://leetcode.cn/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        if (obstacleGrid[rows-1][cols-1] == 1) {
            return 0;
        }

        vector<int> dp(cols, 0);
        for (int col = cols-1; col >= 0; --col) {
            if (obstacleGrid[rows-1][col] == 0) {
                dp[col] = 1;
            }
            else {
                break;
            }
        }

        for (int row = rows-2; row >= 0; --row) {
            if (obstacleGrid[row][cols-1] == 1) {
                dp[cols-1] = 0;
            }
            for (int col = cols-2; col >= 0; --col) {
                if (obstacleGrid[row][col] == 1) {
                    dp[col] = 0;
                }
                else {
                    dp[col] = dp[col] + dp[col+1];
                }
            }
        }

        return dp[0];
    }
};
