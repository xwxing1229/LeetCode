// https://leetcode.cn/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        if (rows == 1) {
            res.insert(res.end(), matrix[0].begin(), matrix[0].end());
            return res;
        }
        else if (cols == 1) {
            for (int row = 0; row < rows; ++row) {
                res.push_back(matrix[row][0]);
            }
            return res;
        }
        else {
            res.insert(res.end(), matrix[0].begin(), matrix[0].end());
            for (int row = 1; row < rows-1; ++row) {
                res.push_back(matrix[row][cols-1]);
            }
            for (int col = cols-1; col >= 0; --col) {
                res.push_back(matrix[rows-1][col]);
            }
            for (int row = rows-2; row > 0; --row) {
                res.push_back(matrix[row][0]);
            }

            if ((rows == 2) || (cols == 2)) {
                return res;
            }
            else {
                vector<vector<int>> tmp(matrix);
                tmp.erase(tmp.begin());
                tmp.pop_back();
                for (int row = 0; row < tmp.size(); ++row) {
                    tmp[row].erase(tmp[row].begin());
                    tmp[row].pop_back();
                }
                return spiralOrder(tmp);
            }
        }
    }
private:
    vector<int> res;
};
