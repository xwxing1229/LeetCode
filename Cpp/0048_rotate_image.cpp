// https://leetcode.cn/problems/rotate-image/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Split the matrix into four regions, excluding the center.
        int n = matrix.size();
        int row_max = n/2-1, col_max = n/2+n%2-1;
        for (int i = 0; i <= row_max; ++i) {
            for (int j = 0; j <= col_max; ++j) {
                int tl = matrix[i][j];
                int tr = matrix[j][n-1-i];
                int br = matrix[n-1-i][n-1-j];
                int bl = matrix[n-1-j][i];
                matrix[i][j] = bl;
                matrix[j][n-1-i] = tl;
                matrix[n-1-i][n-1-j] = tr;
                matrix[n-1-j][i] = br;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    sol.rotate(matrix);
    for (const auto &row: matrix) {
        for (const auto &val: row) {
            cout << val << ", ";
        }
        cout << '\n';
    }
    return 0;
}