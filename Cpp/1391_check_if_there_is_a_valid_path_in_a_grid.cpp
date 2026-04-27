// https://leetcode.cn/problems/check-if-there-is-a-valid-path-in-a-grid/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        unordered_map<string, pair<int, int>> encode = {
            {"left", {0,-1}},
            {"right", {0,1}},
            {"up", {-1,0}},
            {"down", {1,0}}
        };
        unordered_map<int, unordered_set<string>> forward = {
            {1, {"left", "right"}},
            {2, {"up", "down"}},
            {3, {"left", "down"}},
            {4, {"right", "down"}},
            {5, {"left", "up"}},
            {6, {"right", "up"}}
        };

        auto IsForwardValid = [&](int i0, int j0, int i1, int j1) {
            int street = grid[i0][j0];
            for (const auto &direction: forward[street]) {
                auto [di, dj] = encode[direction];
                if (i0 + di == i1 && j0 + dj == j1) {
                    return true;
                }
            }
            return false;
        };
        
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        seen[0][0] = true;
        while (!q.empty()) {
            auto [i0, j0] = q.front();
            q.pop();
            if (i0 == m - 1 && j0 == n - 1) {
                return true;
            }
            for (const auto &direction: forward[grid[i0][j0]]) {
                auto [di, dj] = encode[direction];
                int i = i0 + di, j = j0 + dj;
                if (i >= 0 && i < m && j >= 0 && j < n
                    && IsForwardValid(i, j, i0, j0)
                    && !seen[i][j]) {
                    q.push({i, j});
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
        {2,4,3},
        {6,5,2}
    };
    cout << sol.hasValidPath(grid) << '\n';
    return 0;
}