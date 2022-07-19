// https://leetcode.cn/problems/maximal-square/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res_sqrt = 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> dp(cols, 0);
        for (int col = 0; col < cols; ++col) {
            if (matrix[0][col] == '1') {
                dp[col] = 1;
                res_sqrt = 1;
            }
        }
        for (int row = 1; row < rows; ++row) {
            int last = dp[0];
            if (matrix[row][0] == '1') {
                dp[0] = 1;
            }
            else {
                dp[0] = 0;
            }
            res_sqrt = max(res_sqrt, dp[0]);
            for (int col = 1; col < cols; ++col) {
                if (matrix[row][col] == '1') {
                    int tmp = min(last, min(dp[col-1], dp[col])) + 1;
                    last = dp[col];
                    dp[col] = tmp;
                    res_sqrt = max(res_sqrt, tmp);
                }
                else {
                    dp[col] = 0;
                }
            }
        }
        return res_sqrt * res_sqrt;
    }
};
