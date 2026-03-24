// https://leetcode.cn/problems/construct-product-matrix/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int mod = 12345;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        
        long suffix = 1;
        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                res[i][j] = suffix;
                suffix = suffix * grid[i][j] % mod;
            }
        }
        long prefix = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res[i][j] = prefix * res[i][j] % mod;
                prefix = prefix * grid[i][j] % mod;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {1,2}, {3,4}
    };
    auto res = sol.constructProductMatrix(grid);
    for (const auto &row: res) {
        for (const auto &val: row) {
            cout << val << ", ";
        }
        cout << '\n';
    }
    return 0;
}