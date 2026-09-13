// https://leetcode.cn/problems/image-overlap/

#include <vector>

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int res = 0;
        for (int x = 1-n; x < n; ++x) {
            for (int y = 1-n; y < n; ++y) {
                int tmp = 0;
                for (int i = max(0, -x); i < min(n, n-x); ++i) {
                    for (int j = max(0, -y); j < min(n, n-y); ++j) {
                        tmp += img1[i][j] * img2[i+x][j+y];
                    }
                }
                res = max(res, tmp);
            }
        }
        return res;
    }
};