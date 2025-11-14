// https://leetcode.cn/problems/increment-submatrices-by-one/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n+1, vector<int>(n+1, 0));
        for (const auto &q: queries) {
            int i1 = q[0], j1 = q[1], i2 = q[2], j2 = q[3];
            diff[i1][j1] += 1;
            diff[i2+1][j1] -= 1;
            diff[i1][j2+1] -= 1;
            diff[i2+1][j2+1] += 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                diff[i][j] += diff[i-1][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                diff[i][j] += diff[i][j-1];
            }
        }

        vector<vector<int>> res(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res[i][j] = diff[i][j];
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    int n = 3;
    vector<vector<int>> queries = {{1,1,2,2}, {0,0,1,1}};
    auto res = sol.rangeAddQueries(n, queries);
    for (const auto &row: res) {
        for (const int &val: row) cout << val << ", ";
        cout << '\n';
    }
    return 0;
}