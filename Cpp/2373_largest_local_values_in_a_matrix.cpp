// https://leetcode.cn/problems/largest-local-values-in-a-matrix/

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n-2, vector<int>(n-2, 0));
        for (int i = 1; i < n-1; ++i) {
            for (int j = 1; j < n-1; ++j) {
                for (int x = i-1; x < i+2; ++x) {
                    for (int y = j-1; y < j+2; ++y) {
                        res[i-1][j-1] = max(res[i-1][j-1], grid[x][y]);
                    }
                }
            }
        }
        return res;
    }
};
