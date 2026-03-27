// https://leetcode.cn/problems/matrix-similarity-after-cyclic-shifts/

#include <iostream>
#include <vector>

using namespace std;
    
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        k %= n;
        int flag = 1;
        for (const auto &row: mat) {
            flag *= -1;
            for (int j = 0; j < n; ++j) {
                if (row[(j+flag*k+n)%n] != row[j]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1,2,1,2},
        {5,5,5,5},
        {6,3,6,3}
    };
    int k = 2;
    cout << sol.areSimilar(mat, k) << '\n';
    return 0;
}