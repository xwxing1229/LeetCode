// https://leetcode.cn/problems/determine-whether-matrix-can-be-obtained-by-rotation/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        auto rotateOnce = [&]() {
            vector<vector<int>> res = mat;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    res[j][n-1-i] = mat[i][j];
                }
            }
            mat = move(res);
        };

        auto isValid = [&]() {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (mat[i][j] != target[i][j]) {
                        return false;
                    }
                }
            }
            return true;
        };

        for (int i = 0; i < 4; ++i) {
            if (isValid()) {
                return true;
            }
            rotateOnce();
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {0,1},
        {1,0}
    };
    vector<vector<int>> target = {
        {1,0},
        {0,1}
    };
    cout << sol.findRotation(mat, target) << '\n';
    return 0;
}