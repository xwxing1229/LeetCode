// https://leetcode.cn/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 1) {
            res = {{1}};
            return res;
        }
        else if (numRows == 2) {
            res = {{1}, {1,1}};
            return res;
        }
        else {
            res = generate(numRows-1);
            vector<int> row(numRows, 1);
            for (int i = 1; i < numRows-1; ++i) {
                row[i] = res[numRows-2][i-1] + res[numRows-2][i];
            }
            res.push_back(row);
            return res;
        }
    }
};
