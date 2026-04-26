// https://leetcode.cn/problems/detect-cycles-in-2d-grid/

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        function<bool(int, int, int, int)> dfs = [&](int x, int y, int x_prev, int y_prev) {
            visited[x][y] = true;
            for (const auto &d: directions) {
                int x_next = x + d[0], y_next = y + d[1];
                if (x_next < 0 || x_next >= m || y_next < 0 || y_next >= n || grid[x_next][y_next] != grid[x][y]) {
                    continue;
                }
                if (visited[x_next][y_next]) {
                    if (x_next != x_prev || y_next != y_prev) {
                        return true;
                    }
                    continue;
                }
                if (dfs(x_next, y_next, x, y)) {
                    return true;
                }
            }
            return false;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j] && dfs(i, j, -1, -1)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> grid = {
        {'a','a','a','a'},
        {'a','b','b','a'},
        {'a','b','b','a'},
        {'a','a','a','a'}
    }; // true
    cout << sol.containsCycle(grid) << '\n';
    return 0;
}