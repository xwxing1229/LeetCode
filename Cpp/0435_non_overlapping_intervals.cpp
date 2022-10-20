// https://leetcode.cn/problems/non-overlapping-intervals/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& interval1, const vector<int>& interval2) {
                return interval1[1] < interval2[1];
            });
        int cnt = 1, n = intervals.size();
        int right = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] >= right) {
                cnt += 1;
                right = intervals[i][1];
            }
        }
        int res = n - cnt;
        return res;
    }
};
