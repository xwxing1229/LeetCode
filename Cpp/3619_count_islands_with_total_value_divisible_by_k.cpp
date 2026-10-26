// https://leetcode.cn/problems/count-islands-with-total-value-divisible-by-k/

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0 || seen[i][j]) continue;
                queue<pair<int, int>> q;
                q.push({i, j});
                seen[i][j] = true;
                long long s = grid[i][j];
                while (!q.empty()) {
                    auto [i0, j0] = q.front();
                    q.pop();
                    for (const auto [di, dj]: dirs) {
                        int ni = i0 + di, nj = j0 + dj;
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n
                            && grid[ni][nj] != 0 && !seen[ni][nj]) {
                            q.push({ni, nj});
                            seen[ni][nj] = true;
                            s += grid[ni][nj];
                        }
                    }
                }
                res += (s % k == 0);
            }
        }
        return res;
    }
};