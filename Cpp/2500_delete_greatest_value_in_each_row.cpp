// https://leetcode.cn/problems/delete-greatest-value-in-each-row/

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (auto &row: grid) {
            sort(row.begin(), row.end());
        }
        int res = 0;
        for (int j = 0; j < grid[0].size(); ++j) {
            int tmp = grid[0][j];
            for (int i = 1; i < grid.size(); ++i) {
                tmp = max(tmp, grid[i][j]);
            }
            res += tmp;
        }
        return res;
    }
};