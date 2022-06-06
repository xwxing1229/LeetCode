// https://leetcode.cn/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& interval1, const vector<int>& interval2) {
                return interval1[0] < interval2[0];
            });
        
        vector<vector<int>> res = {intervals[0]};
        int right = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (right < intervals[i][0]) {
                res.push_back(intervals[i]);
                right = intervals[i][1];
            }
            else if (right < intervals[i][1]) {
                right = intervals[i][1];
                res.back()[1] = right;
            }
        }
        return res;
    }
};
