// https://leetcode.cn/problems/find-the-width-of-columns-of-a-grid/

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                res[i] = max(res[i], (int)to_string(grid[j][i]).size());
            }
        }
        return res;
    }
};
