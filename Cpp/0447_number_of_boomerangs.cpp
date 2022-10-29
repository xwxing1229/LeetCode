// https://leetcode.cn/problems/number-of-boomerangs/

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        for (vector<int>& p: points) {
            unordered_map<int, int> cnt;
            for (vector<int>& q: points) {
                int dist = (p[0]-q[0]) * (p[0]-q[0]) + (p[1]-q[1]) * (p[1]-q[1]);
                cnt[dist] += 1;
            }

            for (auto it = cnt.begin(); it != cnt.end(); ++it) {
                res += it->second * (it->second - 1);
            }
        }
        return res;
    }
};
