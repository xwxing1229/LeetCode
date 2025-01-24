// https://leetcode.cn/problems/count-ways-to-group-overlapping-ranges/

class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end(), [](const vector<int> &r1, const vector<int> &r2) {
            return r1[0] < r2[0] || (r1[0] == r2[0] && r1[1] < r2[1]);
        });
        int right = ranges[0][1], groups = 1;
        for (auto &r: ranges) {
            if (r[0] <= right) {
                right = max(right, r[1]);
            }
            else {
                groups += 1;
                right = r[1];
            }
        }

        int MOD = 1e9 + 7;
        int res = 1;
        for (int i = 0; i < groups; ++i) {
            res = res * 2 % MOD;
        }
        return res;
    }
};
