// https://leetcode.cn/problems/minimum-rectangles-to-cover-points/
        
class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());
        int res = 1;
        int end = points[0][0] + w;
        for (auto &p: points) {
            if (p[0] > end) {
                res += 1;
                end = p[0] + w;
            }
        }
        return res;
    }
};
