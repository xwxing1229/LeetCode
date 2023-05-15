// https://leetcode.cn/problems/flip-columns-for-maximum-number-of-equal-rows/

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        unordered_map<string, int> cnt;
        for (int row = 0; row < rows; ++row) {
            string s(cols, '0');
            for (int col = 0; col < cols; ++col) {
                if ((matrix[row][0] == 0 && matrix[row][col] == 1) ||
                    (matrix[row][0] == 1 && matrix[row][col] == 0)) {
                    s[col] = '1';
                }
            }
            cnt[s] += 1;
        }
        int res = 0;
        for (auto it = cnt.begin(); it != cnt.end(); ++it) {
            if (res < it->second) {
                res = it->second;
            }
        }
        return res;
    }
};
