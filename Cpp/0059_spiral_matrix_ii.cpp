// https://leetcode.cn/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        generateCircle(n, 0, 1, res);
        return res;
    }

private:
    void generateCircle(int n, int start_row, int num,
        vector<vector<int>> &matrix) {
        if (start_row == (n+1) / 2) {
            return;
        }
        int end_row = n - 1 - start_row;
        if (start_row == end_row) {
            matrix[start_row][start_row] = num;
            return;
        }

        for (int col = start_row; col < end_row+1; ++col) {
            matrix[start_row][col] = num;
            num = num + 1;
        }
        for (int row = start_row+1; row < end_row; ++row) {
            matrix[row][end_row] = num;
            num = num + 1;
        }
        for (int col = end_row; col > start_row-1; --col) {
            matrix[end_row][col] = num;
            num = num + 1;
        }
        for (int row = end_row-1; row > start_row; --row) {
            matrix[row][start_row] = num;
            num = num + 1;
        }
        
        generateCircle(n, start_row+1, num, matrix);
    }
};
