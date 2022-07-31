// https://leetcode.cn/problems/range-sum-query-2d-immutable/

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        sum_to_now.resize(rows, vector<int>(cols));
        int tmp = 0;
        for (int col = 0; col < cols; ++col) {
            tmp = tmp + matrix[0][col];
            sum_to_now[0][col] = tmp;
        }
        for (int row = 1; row < rows; ++row) {
            tmp = 0;
            for (int col = 0; col < cols; ++col) {
                tmp = tmp + matrix[row][col];
                sum_to_now[row][col] = tmp + sum_to_now[row-1][col];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if ((row1 == 0) && (col1 == 0)) {
            return sum_to_now[row2][col2];
        }
        else if ((row1 == 0) && (col1 != 0)) {
            return sum_to_now[row2][col2] - sum_to_now[row2][col1-1];
        }
        else if ((row1 != 0) && (col1 == 0)) {
            return sum_to_now[row2][col2] - sum_to_now[row1-1][col2];
        }
        else {
            return sum_to_now[row2][col2] - sum_to_now[row1-1][col2] -
                sum_to_now[row2][col1-1] + sum_to_now[row1-1][col1-1];
        }
    }

private:
    vector<vector<int>> sum_to_now;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */