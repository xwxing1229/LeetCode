// https://leetcode.cn/problems/row-with-maximum-ones/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> res = {0, 0}; // idx, cnt
        for (int i = 0; i < mat.size(); ++i) {
            int s = 0;
            for (auto &val: mat[i]) s += val;
            if (s > res[1]) {
                res[0] = i;
                res[1] = s;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {0,0,0},
        {0,1,1}
    };
    auto res = sol.rowAndMaximumOnes(mat);
    cout << res[0] << ", " << res[1] << '\n';
    return 0;
}