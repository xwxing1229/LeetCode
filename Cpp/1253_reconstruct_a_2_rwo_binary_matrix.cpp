// https://leetcode.cn/problems/reconstruct-a-2-row-binary-matrix/

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>> res(2, vector<int>(n, 0));
        vector<vector<int>> res_invalid;
        for (int i = 0; i < n; ++i) {
            if (colsum[i] == 2) {
                if (upper > 0 && lower > 0) {
                    res[0][i] = 1;
                    res[1][i] = 1;
                    upper -= 1;
                    lower -= 1;
                }
                else {
                    return res_invalid;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (colsum[i] == 1) {
                if (upper > 0) {
                    res[0][i] = 1;
                    upper -= 1;
                }
                else if (lower > 0) {
                    res[1][i] = 1;
                    lower -= 1;
                }
                else {
                    return res_invalid;
                }
            }
        }
        if (upper != 0 or lower != 0) {
            return res_invalid;
        }
        return res;
    }
};