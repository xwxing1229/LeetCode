// https://leetcode.cn/problems/equal-sum-grid-partition-i/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        auto canPartition = [](const vector<vector<int>> &grid) {
            int m = grid.size(), n = grid[0].size();
            vector<long> suffix(m, 0);
            long tmp = 0;
            for (int i = m-1; i > 0; --i) {
                for (int j = n-1; j >= 0; --j) {
                    tmp += grid[i][j];
                }
                suffix[i-1] = tmp;
            }
            long prefix = 0;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    prefix += grid[i][j];
                }
                if (prefix == suffix[i]) return true;
            }
            return false;
        };

        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> grid_T(n, vector<int>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                grid_T[j][i] = grid[i][j];
            }
        }
        return canPartition(grid) || canPartition(grid_T);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {1, 4},
        {2, 3}
    };
    cout << sol.canPartitionGrid(grid) << '\n';
    return 0;
}