// https://leetcode.cn/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int rot = 0, orange = 0;
        queue<pair<int, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    orange += 1;
                }
                else if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                    orange += 1;
                    rot += 1;
                    visited[i][j] = 1;
                }
            }
        }
        if (rot == orange) return 0;

        int res = -1;
        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while (!q.empty()) {
            res += 1;
            int num = q.size();
            for (int k = 0; k < num; ++k) {
                auto cur = q.front();
                q.pop();
                for (auto &d: dirs) {
                    int i = cur.first+d.first, j = cur.second+d.second;
                    if (i < 0 || i >= m || j < 0 || j >= n) continue;
                    if (grid[i][j] == 0 || visited[i][j] == 1) continue;
                    q.push(make_pair(i, j));
                    rot += 1;
                    visited[i][j] = 1;
                }
            }
        }
        return rot == orange ? res : -1;
    }
};
