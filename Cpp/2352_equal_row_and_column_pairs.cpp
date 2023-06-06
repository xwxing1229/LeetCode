// https://leetcode.cn/problems/equal-row-and-column-pairs/

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> rows, cols;
        int n = grid.size();
        for (int i = 0; i < n; ++i) {
            string s;
            for (int j = 0; j < n; ++j) {
                s += (to_string(grid[i][j]) + '-');
            }
            rows[s] += 1;
        }
        for (int j = 0; j < n; ++j) {
            string s;
            for (int i = 0; i < n; ++i) {
                s += (to_string(grid[i][j]) + '-');
            }
            cols[s] += 1;
        }
        int res = 0;
        for (auto it = rows.begin(); it != rows.end(); ++it) {
            res += it->second * cols[it->first];
        }
        return res;
    }
};
