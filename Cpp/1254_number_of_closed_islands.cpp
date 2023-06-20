// https://leetcode.cn/problems/number-of-closed-islands/

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) continue;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                grid[i][j] = 1;
                bool closed = true;
                while (!q.empty()) {
                    auto [curi, curj] = q.front();
                    q.pop();
                    if (curi == 0 || curi == m-1 || curj == 0 || curj == n-1) {
                        closed = false;
                    }
                    for (auto d: dirs) {
                        int x = curi + d.first, y = curj + d.second;
                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0) {
                            q.push(make_pair(x, y));
                            grid[x][y] = 1;
                        }
                    }
                }
                if (closed) {
                    res += 1;
                }
            }
        }
        return res;
    }
};