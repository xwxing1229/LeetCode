// https://leetcode.cn/problems/count-submatrices-with-equal-frequency-of-x-and-y/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        // dp[j][0]: count of 'X' in the jth column.
        // dp[j][1]: count of 'Y' in the jth column.
        vector<vector<int>> dp(n, vector<int>(2, 0));
        for (int i = 0; i < m; ++i) {
            int cntx = 0, cnty = 0;
            for (int j = 0; j < n; ++j) {
                char ch = grid[i][j];
                if (ch != '.') {
                    dp[j][ch-'X'] += 1;
                }
                cntx += dp[j][0];
                cnty += dp[j][1];
                if (cntx > 0 && cntx == cnty) {
                    res += 1;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> grid = {
        {'X','Y','.'},
        {'Y','.','.'}
    };
    cout << sol.numberOfSubmatrices(grid) << '\n';
    return 0;
}