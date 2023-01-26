// https://leetcode.cn/problems/queries-on-number-of-points-inside-a-circle/

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int x = queries[i][0], y = queries[i][1], r2 = queries[i][2] * queries[i][2];
            int cnt = 0;
            for (auto p: points) {
                if ((p[0] - x) * (p[0] - x) + (p[1] - y) * (p[1] - y) <= r2) {
                    cnt += 1;
                }
            }
            res[i] = cnt;
        }
        return res;
    }
};
