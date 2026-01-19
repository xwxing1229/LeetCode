// https://leetcode.cn/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<long>> cumsum(m+1, vector<long>(n+1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cumsum[i+1][j+1] = cumsum[i+1][j] - cumsum[i][j] + cumsum[i][j+1] + mat[i][j];
            }
        }

        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int side_min = res + 1;
                int side_max = min(m-i, n-j);
                for (int side = side_min; side <= side_max; ++side) {
                    long curr = cumsum[i+side][j+side] - cumsum[i+side][j] - cumsum[i][j+side] + cumsum[i][j];
                    if (curr > threshold) {
                        break;
                    }
                    else if (res < side) {
                        res = side;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1,1,3,2,4,3,2},
        {1,1,3,2,4,3,2},
        {1,1,3,2,4,3,2}
    };
    int threshold = 4;
    cout << sol.maxSideLength(mat, threshold) << '\n';
    return 0;
}