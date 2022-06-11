// https://leetcode.cn/problems/simplify-path/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        bool set_first_row = false, set_first_col = false;
        for (int col = 0; col < cols; ++col) {
            if (matrix[0][col] == 0) {
                set_first_row = true;
                break;
            }
        }
        for (int row = 0; row < rows; ++row) {
            if (matrix[row][0] == 0) {
                set_first_col = true;
                break;
            }
        }

        for (int row = 1; row < rows; ++row) {
            for (int col = 1; col < cols; ++col) {
                if (matrix[row][col] == 0) {
                    matrix[0][col] = 0;
                    matrix[row][0] = 0;
                }
            }
        }

        for (int row = 1; row < rows; ++row) {
            for (int col = 1; col < cols; ++col) {
                if ((matrix[0][col] == 0) || (matrix[row][0] == 0)) {
                    matrix[row][col] = 0;
                }
            }
        }
        if (set_first_row) {
            for (int col = 0; col < cols; ++col) {
                matrix[0][col] = 0;
            }
        }
        if (set_first_col) {
            for (int row = 0; row < rows; ++row) {
                matrix[row][0] = 0;
            }
        }
    }
};

int main() {
    Solution solu;
    vector<vector<int>> matrix = {
        {1,1,1}, {1,0,1}, {1,1,1}
    };
    
    solu.setZeroes(matrix);

    for (vector<int> row: matrix) {
        for (int i: row) {
            cout << i << ", ";
        }
        cout << '\n';
    }
    return 0;
}