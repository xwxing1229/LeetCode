// https://leetcode.cn/problems/minimum-falling-path-sum/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp = matrix[0], dp_pre = matrix[0];
        for (int i = 1; i < n; ++i) {
            dp[0] = min(dp_pre[0], dp_pre[1]) + matrix[i][0];
            dp[n-1] = min(dp_pre[n-1], dp_pre[n-2]) + matrix[i][n-1];
            for (int j = 1; j < n-1; ++j) {
                dp[j] = min(dp_pre[j], min(dp_pre[j-1], dp_pre[j+1])) + matrix[i][j];
            }
            dp_pre = dp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};
