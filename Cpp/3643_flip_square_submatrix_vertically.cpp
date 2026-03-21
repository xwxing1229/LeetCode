// https://leetcode.cn/problems/flip-square-submatrix-vertically/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>> res = grid;
        int s = x + x + k - 1;
        for (int i = x; i < x+k/2; ++i) {
            for (int j = y; j < y+k; ++j) {
                res[i][j] = grid[s-i][j];
                res[s-i][j] = grid[i][j];
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {3,4,2,3},
        {2,3,4,2}
    };
    int x = 0;
    int y = 2;
    int k = 2;
    auto res = sol.reverseSubmatrix(grid, x, y, k);
    for (const auto &row: res) {
        for (const auto &val: row) {
            cout << val << ", ";
        }
        cout << '\n';
    }
    return 0;
}