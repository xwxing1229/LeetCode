// https://leetcode.cn/problems/first-completely-painted-row-or-column/

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int,int>> val_idx;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                val_idx[mat[i][j]] = make_pair(i, j);
            }
        }
        int res = -1;
        vector<int> paintrow(m, 0), paintcol(n, 0);
        for (int i = 0; i < arr.size(); ++i) {
            int val = arr[i];
            int row = val_idx[val].first, col = val_idx[val].second;
            paintrow[row] += 1;
            paintcol[col] += 1;
            if (paintrow[row] == n || paintcol[col] == m) {
                res = i;
                break;
            }
        }
        return res;
    }
};