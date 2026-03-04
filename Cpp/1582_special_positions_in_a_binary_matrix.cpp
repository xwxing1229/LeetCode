// https://leetcode.cn/problems/special-positions-in-a-binary-matrix/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> rec_row(m), rec_col(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    rec_row[i].push_back(j);
                    rec_col[j].push_back(i);
                }
            }
        }
        int res = 0;
        for (const auto &rec: rec_row) {
            if (rec.empty() || rec.size() > 1) {
                continue;
            }
            else if (rec_col[rec[0]].size() == 1) {
                res += 1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1,0,0},
        {0,0,1},
        {1,0,0}
    };
    cout << sol.numSpecial(mat) << '\n';
    return 0;
}