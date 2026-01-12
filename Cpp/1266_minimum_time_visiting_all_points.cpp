// https://leetcode.cn/problems/minimum-time-visiting-all-points/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        int n = points.size();
        for (int i = 1; i < n; ++i) {
            const auto &prev = points[i-1], curr = points[i];
            res += max(abs(curr[0] - prev[0]), abs(curr[1] - prev[1]));
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{1,1}, {3,4}, {-1,0}};
    cout << sol.minTimeToVisitAllPoints(points) << '\n';
    return 0;
}