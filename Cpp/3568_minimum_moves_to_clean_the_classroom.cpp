// https://leetcode.cn/problems/minimum-moves-to-clean-the-classroom/

#include <vector>
#include <string>
#include <array>

using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        vector<vector<int>> idx(m, vector<int>(n));
        int cnt = 0; // count of litter
        int sx = 0, sy = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char ch = classroom[i][j];
                if (ch == 'S') {
                    sx = i;
                    sy = j;
                }
                else if (ch == 'L') {
                    idx[i][j] = (1 << cnt);
                    cnt += 1;
                }
            }
        }
        if (cnt == 0) return 0;
        
        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int res = 0;

        vector<array<int, 4>> q;
        q.push_back({sx, sy, energy, 0});
        vector<vector<vector<int>>> max_energy(m, vector<vector<int>>(n, vector<int>(1<<cnt, -1)));
        max_energy[sx][sy][0] = energy;
        int full_mask = (1 << cnt) - 1;
        while (!q.empty()) {
            auto tmp = move(q);
            for (const auto &[x, y, e, mask]: tmp) {
                if (mask == full_mask) return res;
                if (e == 0) continue;
                for (const auto &d: dirs) {
                    int nx = x + d.first, ny = y + d.second;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && classroom[nx][ny] != 'X') {
                        int ne = e - 1;
                        if (classroom[nx][ny] == 'R') ne = energy;
                        int nmask = (mask | idx[nx][ny]);
                        if (ne > max_energy[nx][ny][nmask]) {
                            q.push_back({nx, ny, ne, nmask});
                            max_energy[nx][ny][nmask] = ne;
                        }
                    }
                }
            }
            res += 1;
        }
        return -1;
    }
};