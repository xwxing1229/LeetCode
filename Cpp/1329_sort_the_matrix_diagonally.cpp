// https://leetcode.cn/problems/sort-the-matrix-diagonally/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for (int row = m-1; row >= 0; --row) {
            update(mat, row, 0);
        }
        for (int col = 1; col < n; ++col) {
            update(mat, 0, col);
        }
        return mat;
    }

    void update(vector<vector<int>> &mat, int i0, int j0) {
        vector<int> diag;
        int i = i0, j = j0;
        int m = mat.size(), n = mat[0].size();
        while (i < m && j < n) {
            diag.push_back(mat[i][j]);
            i += 1;
            j += 1;
        }
        sort(diag.begin(), diag.end());
        i = i0;
        j = j0;
        for (int val: diag) {
            mat[i][j] = val;
            i += 1;
            j += 1;
        }
    }
};
