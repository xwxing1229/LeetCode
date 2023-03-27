// https://leetcode.cn/problems/diagonal-traverse/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int i = 0, j = 0, rows = mat.size(), cols = mat[0].size();
        int cnt = 0, total = rows * cols;
        bool up = true;
        while (cnt < total) {
            res.push_back(mat[i][j]);
            cnt += 1;
            if (up) {
                i -= 1;
                j += 1;
                if (i < 0) {
                    if (j < cols) {
                        i += 1;
                    }
                    else {
                        i += 2;
                        j -= 1;
                    }
                    up = false;
                }
                else if (j >= cols) {
                    i += 2;
                    j -= 1;
                    up = false;
                }
            }
            else {
                i += 1;
                j -= 1;
                if (j < 0) {
                    if (i < rows) {
                        j += 1;
                    }
                    else {
                        j += 2;
                        i -= 1;
                    }
                    up = true;
                }
                else if (i >= rows) {
                    j += 2;
                    i -= 1;
                    up = true;
                }
            }
        }
        return res;
    }
};
