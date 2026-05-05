// https://leetcode.cn/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/

#include <iostream>
#include <vector>

using namespace std;
    
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        res += (dp[0][0] <= k);
        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
            res += (dp[i][0] <= k);
        }
        for (int j = 1; j < n; ++j) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
            res += (dp[0][j] <= k);
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + grid[i][j];
                res += (dp[i][j] <= k);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {7,2,9},
        {1,5,0},
        {2,6,6}
    };
    int k = 20;
    cout << sol.countSubmatrices(grid, k) << '\n';
    return 0;
}