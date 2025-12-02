// https://leetcode.cn/problems/count-number-of-trapezoids-i/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int> &v1, const vector<int> &v2) {
            return v1[1] < v2[1] || (v1[1] == v2[1] && v1[0] < v2[0]);
        });
        int res = 0, mod = 1000000007;
        int n = points.size(), i = 0, pre = points[0][1];
        int bottom = 0;
        while (i < n) {
            long top = 0;
            while (i < n && points[i][1] == pre) {
                i += 1;
                top += 1;
            }
            long top_valid = top * (top - 1) / 2 % mod;
            res = (res + top_valid * bottom % mod) % mod;
            bottom += top_valid;
            if (i < n) pre = points[i][1];
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{1,0},{2,0},{3,0},{2,2},{3,2}};
    cout << sol.countTrapezoids(points) << '\n';
    return 0;
}