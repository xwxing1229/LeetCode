// https://leetcode.cn/problems/find-the-safest-path-in-a-grid/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0;

        vector<vector<int>> distance(n, vector<int>(n, -1));
        vector<pair<int, int>> direction = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    distance[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            const auto [i0, j0] = q.front();
            q.pop();
            for (const auto [di, dj]: direction) {
                int i = i0 + di, j = j0 + dj;
                if (i >= 0 && i < n && j >= 0 && j < n && distance[i][j] == -1) {
                    distance[i][j] = distance[i0][j0] + 1;
                    q.push({i, j});
                }
            }
        }

        auto check = [&](const int dist) {
            queue<pair<int, int>> q;
            q.push({0, 0});
            vector<vector<bool>> visit(n, vector<bool>(n, false));
            visit[0][0] = true;
            while (!q.empty()) {
                const auto [i0, j0] = q.front();
                q.pop();
                if (i0 == n-1 && j0 == n-1) return true;
                for (const auto [di, dj]: direction) {
                    int i = i0 + di, j = j0 + dj;
                    if (i >= 0 && i < n && j >= 0 && j < n && !visit[i][j] && distance[i][j] >= dist) {
                        q.push({i, j});
                        visit[i][j] = true;
                    }
                }
            }
            return false;
        };

        int res = 0;
        int left = 0, right = min(distance[0][0], distance[n-1][n-1]);
        while (left <= right) {
            int mid = (left + right) / 2;
            if (check(mid)) {
                res = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {0, 0, 1},
        {0, 0, 0},
        {0, 0, 0}
    };
    cout << sol.maximumSafenessFactor(grid) << '\n';
    return 0;
}