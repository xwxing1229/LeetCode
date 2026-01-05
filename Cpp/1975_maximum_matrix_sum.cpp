// https://leetcode.cn/problems/maximum-matrix-sum/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long res = 0;
        int neg_cnt = 0, abs_min = -1;
        for (const auto &row: matrix) {
            for (const auto &num: row) {
                int val = num;
                if (val < 0) {
                    val = -num;
                    neg_cnt += 1;
                }
                res += val;
                if (abs_min < 0 || abs_min >= val) {
                    abs_min = val;
                }
            }
        }
        if (neg_cnt % 2) {
            res -= 2 * abs_min;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {-1, -2, -3},
        {1, 2, 3}
    };
    cout << sol.maxMatrixSum(matrix) << '\n';
    return 0;
}