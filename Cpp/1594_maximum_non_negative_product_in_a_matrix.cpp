// https://leetcode.cn/problems/maximum-non-negative-product-in-a-matrix/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int mod = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        vector<vector<pair<long long, long long>>> dp(m, vector<pair<long long, long long>>(n));
        dp[0][0].first = grid[0][0];
        dp[0][0].second = grid[0][0];
        for (int i = 1; i < m; ++i) {
            dp[i][0].first = dp[i-1][0].first * grid[i][0];
            dp[i][0].second = dp[i][0].first;
        }
        for (int j = 1; j < n; ++j) {
            dp[0][j].first = dp[0][j-1].first * grid[0][j];
            dp[0][j].second = dp[0][j].first;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                int val = grid[i][j];
                long long tmp1 = dp[i-1][j].first * val;
                long long tmp2 = dp[i-1][j].second * val;
                long long tmp3 = dp[i][j-1].first * val;
                long long tmp4 = dp[i][j-1].second * val;
                dp[i][j].first = min(min(tmp1, tmp2), min(tmp3, tmp4));
                dp[i][j].second = max(max(tmp1, tmp2), max(tmp3, tmp4));
            }
        }
        auto tmp = dp[m-1][n-1].second;
        return tmp >= 0 ? tmp % mod : -1;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {-1,-2,-3},
        {-2,-3,-3},
        {-3,-3,-2}
    };
    cout << sol.maxProductPath(grid) << '\n';
    return 0;
}