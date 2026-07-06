// https://leetcode.cn/problems/remove-covered-intervals/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int res = intervals.size();
        sort(intervals.begin(), intervals.end(), [&](vector<int> &inti, vector<int> &intj) {
            return inti[0] <= intj[0] || (inti[0] == intj[0] && inti[1] >= intj[1]);
        });
        int right_max = intervals[0][1] - 1;
        for (const auto &interval: intervals) {
            if (interval[1] <= right_max) {
                res -= 1;
            }
            right_max = max(right_max, interval[1]);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {
        {1,4}, {3,6}, {2,8}
    };
    cout << sol.removeCoveredIntervals(intervals) << '\n';
    return 0;
}