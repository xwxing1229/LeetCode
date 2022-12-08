// https://leetcode.cn/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int res = -1, dist = -1;
        for (int i = 0; i < points.size(); ++i) {
            if ((points[i][0] == x) || (points[i][1] == y)) {
                int d = abs(points[i][0] - x) + abs(points[i][1] - y);
                if ((dist < 0) || (d < dist)) {
                    res = i;
                    dist = d;
                }
            }
        }
        return res;
    }
};
