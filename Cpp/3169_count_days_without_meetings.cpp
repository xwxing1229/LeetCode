// https://leetcode.cn/problems/count-days-without-meetings/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int left = meetings[0][0], right = meetings[0][1];
        int res = left - 1;
        for (const auto &m: meetings) {
            if (right + 1 < m[0]) {
                res += m[0] - right - 1;
                left = m[0];
            }
            right = max(right, m[1]);
        }
        res += days - right;
        return res;
    }
};

int main() {
    Solution sol;
    int days = 10;
    vector<vector<int>> meetings = {{5,7}, {1,3}, {9,10}};
    cout << sol.countDays(days, meetings) << '\n';
    return 0;
}