// https://leetcode.cn/problems/minimum-cost-to-cut-a-stick/

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int i = m-3; i >= 0; --i) {
            for (int j = i+2; j < m; ++j) {
                int tmp = dp[i][i+1] + dp[i+1][j];
                for (int k = i+1; k < j; ++k) {
                    tmp = min(tmp, dp[i][k] + dp[k][j]);
                }
                dp[i][j] = tmp + cuts[j] - cuts[i];
            }
        }
        return dp[0].back();
    }
};
