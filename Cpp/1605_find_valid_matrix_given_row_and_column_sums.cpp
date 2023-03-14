// https://leetcode.cn/problems/find-valid-matrix-given-row-and-column-sums/

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rows = rowSum.size(), cols = colSum.size();
        vector<vector<int>> res(rows, vector<int>(cols, 0));
        int i = 0, j = 0;
        while (i < rows && j < cols) {
            int val = min(rowSum[i], colSum[j]);
            res[i][j] = val;
            rowSum[i] -= val;
            colSum[j] -= val;
            if (rowSum[i] == 0) {
                i += 1;
            }
            if (colSum[j] == 0) {
                j += 1;
            }
        }
        return res;
    }
};
