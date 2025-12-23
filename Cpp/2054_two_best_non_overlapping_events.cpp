// https://leetcode.cn/problems/two-best-non-overlapping-events/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int res = 0;
        sort(events.begin(), events.end(), [](const vector<int> &e1, const vector<int> &e2) {
            return e1[1] < e2[1] || (e1[1] == e2[1] && e1[2] > e2[2]);
        });
        vector<pair<int, int>> stk = {make_pair(0,0)}; // (end_time, value)
        for (const auto &e: events) {
            int start = e[0], end = e[1], value = e[2];
            int left = 0, right = stk.size()-1, best = 0;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (stk[mid].first < start) {
                    best = mid;
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            res = max(res, value + stk[best].second);
            if (value > stk.back().second) {
                stk.push_back(make_pair(end, value));
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> events = {{1,3,2}, {4,5,2}, {2,4,3}};
    cout << sol.maxTwoEvents(events) << '\n';
    return 0;
}