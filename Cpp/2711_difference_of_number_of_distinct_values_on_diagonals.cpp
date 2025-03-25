// https://leetcode.cn/problems/difference-of-number-of-distinct-values-on-diagonals/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
        
class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));

        auto update = [&](int row, int col) {
            unordered_map<int, int> topleft, bottomright;
            int i = row, j = col;
            while (i < m && j < n) {
                bottomright[grid[i][j]] += 1;
                i += 1;
                j += 1;
            }
            i = row;
            j = col;
            while (i < m && j < n) {
                int val = grid[i][j];
                bottomright[val] -= 1;
                if (bottomright[val] <= 0) bottomright.erase(val);

                res[i][j] = abs((int)topleft.size() - (int)bottomright.size());

                topleft[val] += 1;
                i += 1;
                j += 1;
            }
        };

        for (int row = 0; row < m; ++row) update(row, 0);
        for (int col = 1; col < n; ++col) update(0, col);
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{1,2,3}, {3,1,5}, {3,2,1}};
    auto res = sol.differenceOfDistinctValues(grid);
    for (auto &row: res) {
        for (auto val: row) cout << val << ", ";
        cout << '\n';
    }
    return 0;
}