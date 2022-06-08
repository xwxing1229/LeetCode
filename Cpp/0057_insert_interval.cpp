// https://leetcode.cn/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res = {};
        int left = newInterval[0], right = newInterval[1];
        bool inserted = false;
        for (vector<int> interval: intervals) {
            if (interval[1] < left) {
                res.push_back(interval);
            }
            else if (interval[0] > right) {
                if (!inserted) {
                    vector<int> tmp = {left, right};
                    res.push_back(tmp);
                    inserted = true;
                }
                res.push_back(interval);
            }
            else {
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!inserted) {
            vector<int> tmp = {left, right};
            res.push_back(tmp);
        }
        return res;
    }
};
