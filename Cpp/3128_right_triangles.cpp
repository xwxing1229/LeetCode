// https://leetcode.cn/problems/right-triangles/

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<vector<int>>> cnts(rows, vector<vector<int>>(cols, vector<int>(4, 0)));
        for (int i = 0; i < rows; ++i) {
            // Left.
            int cnt = grid[i][0];
            for (int j = 1; j < cols; ++j) {
                cnts[i][j][0] = cnt;
                cnt += grid[i][j];
            }
            // Right.
            cnt = grid[i][cols-1];
            for (int j = cols-2; j >= 0; --j) {
                cnts[i][j][1] = cnt;
                cnt += grid[i][j];
            }
        }
        for (int j = 0; j < cols; ++j) {
            // Above.
            int cnt = grid[0][j];
            for (int i = 1; i < rows; ++i) {
                cnts[i][j][2] = cnt;
                cnt += grid[i][j];
            }
            // Below.
            cnt = grid[rows-1][j];
            for (int i = rows-2; i >= 0; --i) {
                cnts[i][j][3] = cnt;
                cnt += grid[i][j];
            }
        }
        long long res = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    res += ((long long)cnts[i][j][0] + cnts[i][j][1])
                        * ((long long)cnts[i][j][2] + cnts[i][j][3]);
                }
            }
        }
        return res;
    }
};
