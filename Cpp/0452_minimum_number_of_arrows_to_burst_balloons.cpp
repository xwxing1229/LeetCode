// https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
            [](const vector<int>& b1, const vector<int>& b2) {
                return b1[0] < b2[0];
            });
        int res = 1;
        int right = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if (right >= points[i][0]) {
                if (right > points[i][1]) {
                    right = points[i][1];
                }
            }
            else {
                res += 1;
                right = points[i][1];
            }
        }
        return res;
    }
};
