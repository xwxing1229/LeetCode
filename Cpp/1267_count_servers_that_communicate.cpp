// https://leetcode.cn/problems/count-servers-that-communicate/

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_set<int> s;
        for (int i = 0; i < m; ++i) {
            int j = 0;
            while (j < n && grid[i][j] == 0) {
                j += 1;
            }
            int k = i * n + j;
            j += 1;
            while (j < n) {
                if (grid[i][j] == 1) {
                    s.insert(k);
                    s.insert(i * n + j);
                }
                j += 1;
            }
        }
        for (int j = 0; j < n; ++j) {
            int i = 0;
            while (i < m && grid[i][j] == 0) {
                i += 1;
            }
            int k = i * n + j;
            i += 1;
            while (i < m) {
                if (grid[i][j] == 1) {
                    s.insert(k);
                    s.insert(i * n + j);
                }
                i += 1;
            }
        }
        return s.size();
    }
};
