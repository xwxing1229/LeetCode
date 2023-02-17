// https://leetcode.cn/problems/largest-1-bordered-square/

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        // down[i][j]: number of consecutive 1 downwards at (i,j)
        // right[i][j]: number of consecutive 1 rightward at (i,j)
        vector<vector<int>> down(rows, vector<int>(cols, 0));
        vector<vector<int>> right(rows, vector<int>(cols, 0));
        for (int i = rows-1; i >= 0; --i) {
            for (int j = cols-1; j >= 0; --j) {
                if (grid[i][j] == 1) {
                    if (i + 1 < rows) down[i][j] = down[i+1][j] + 1;
                    else down[i][j] = 1;
                    if (j + 1 < cols) right[i][j] = right[i][j+1] + 1;
                    else right[i][j] = 1;
                }
            }
        }

        for (int k = min(rows, cols); k > 0; --k) {
            for (int i = 0; i <= rows - k; ++i) {
                for (int j = 0; j <= cols - k; ++j) {
                    if (down[i][j] >= k && right[i][j] >= k &&
                        down[i][j+k-1] >= k && right[i+k-1][j] >= k) {
                        return k * k;
                    }
                }
            }
        }
        return 0;
    }
};
