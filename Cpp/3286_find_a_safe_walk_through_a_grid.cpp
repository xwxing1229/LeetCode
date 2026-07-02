// https://leetcode.cn/problems/find-a-safe-walk-through-a-grid/

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        vector<pair<int, int>> direction = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        int m = grid.size(), n = grid[0].size();

        priority_queue<tuple<int, int, int>> pq;
        pq.push({health-grid[0][0], 0, 0});
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        seen[0][0] = true;

        while (!pq.empty()) {
            auto [curr, i0, j0] = pq.top();
            pq.pop();
            if (i0 == m-1 && j0 == n-1) {
                return true;
            }
            for (const auto [di, dj]: direction) {
                int i = i0 + di, j = j0 + dj;
                if (i >= 0 && i < m && j >= 0 && j < n
                    && !seen[i][j]
                    && curr-grid[i][j] > 0) {
                    pq.push({curr-grid[i][j], i, j});
                    seen[i][j] = true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {0,1,0,0,0},
        {0,1,0,1,0},
        {0,0,0,1,0}
    };
    int health = 1;
    cout << sol.findSafeWalk(grid, health) << '\n';
    return 0;
}