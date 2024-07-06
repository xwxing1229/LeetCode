// https://leetcode.cn/problems/modify-the-matrix/
        
class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> max_col(n);
        vector<pair<int, int>> replace;
        for (int j = 0; j < n; ++j) {
            int max_val = matrix[0][j];
            for (int i = 0; i < m; ++i) {
                int val = matrix[i][j];
                max_val = max(max_val, val);
                if (val == -1) {
                    replace.push_back(make_pair(i,j));
                }
            }
            max_col[j] = max_val;
        }
        for (auto &idx: replace) {
            matrix[idx.first][idx.second] = max_col[idx.second];
        }
        return matrix;
    }
};
