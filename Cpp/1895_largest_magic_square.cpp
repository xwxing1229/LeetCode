// https://leetcode.cn/problems/largest-magic-square/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cs_row(m, vector<int>(n+1, 0));
        vector<vector<int>> cs_col(m+1, vector<int>(n, 0));
        vector<vector<int>> cs_diag(m+1, vector<int>(n+1, 0));
        vector<vector<int>> cs_anti(m+1, vector<int>(n+1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cs_row[i][j+1] = cs_row[i][j] + grid[i][j];
                cs_col[i+1][j] = cs_col[i][j] + grid[i][j];
                cs_diag[i+1][j+1] = cs_diag[i][j] + grid[i][j];
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = n-1; j >= 0; --j) {
                cs_anti[i+1][j] = cs_anti[i][j+1] + grid[i][j];
            }
        }

        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int k_min = res + 1;
                int k_max = min(m-i, n-j);
                for (int k = k_min; k <= k_max; ++k) {
                    int s = cs_diag[i+k][j+k] - cs_diag[i][j];
                    if (s != cs_anti[i+k][j] - cs_anti[i][j+k]) {
                        continue;
                    }
                    bool valid = true;
                    for (int t = 0; t < k; ++t) {
                        if (s != cs_row[i+t][j+k] - cs_row[i+t][j]) {
                            valid = false;
                            break;
                        }
                        if (s != cs_col[i+k][j+t] - cs_col[i][j+t]) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) {
                        res = k;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {7,1,4,5,6},
        {2,5,1,6,4},
        {1,5,4,3,2},
        {1,2,7,3,4}
    };
    cout << sol.largestMagicSquare(grid) << '\n';
    return 0;
}