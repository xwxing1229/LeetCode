// https://leetcode.cn/problems/coordinate-with-maximum-network-quality/

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int xMin = towers[0][0], xMax = towers[0][0], yMin = towers[0][1], yMax = towers[0][1];
        for (vector<int>& t: towers) {
            int xCur = t[0], yCur = t[1];
            if (xCur < xMin) xMin = xCur;
            if (xCur > xMax) xMax = xCur;
            if (yCur < yMin) yMin = yCur;
            if (yCur > yMax) yMax = yCur;
        }

        vector<int> res(2,0);
        int quality = 0;
        for (int x = xMin; x <= xMax; ++x) {
            for (int y = yMin; y <= yMax; ++y) {
                int q = 0;
                for (vector<int>& t: towers) {
                    float dist = sqrt((x-t[0])*(x-t[0]) + (y-t[1])*(y-t[1]));
                    if (dist <= radius) {
                        q += (t[2] / (1+dist));
                    }
                }
                if (q > quality) {
                    res[0] = x;
                    res[1] = y;
                    quality = q;
                }
            }
        }
        return res;
    }
};
