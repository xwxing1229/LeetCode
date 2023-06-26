// https://leetcode.cn/problems/circle-and-rectangle-overlapping/

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int rsq = radius * radius;
        if (xCenter < x1) {
            if (yCenter > y2) {
                if (dsquare(xCenter, yCenter, x1, y2) <= rsq) return true;
            }
            else if (yCenter > y1) {
                if (xCenter >= x1 - radius) return true;
            }
            else {
                if (dsquare(xCenter, yCenter, x1, y1) <= rsq) return true;
            }
        }
        else if (xCenter < x2) {
            if (yCenter <= y2 + radius && yCenter >= y1 - radius) return true;
        }
        else {
            if (yCenter > y2) {
                if (dsquare(xCenter, yCenter, x2, y2) <= rsq) return true;
            }
            else if (yCenter > y1) {
                if (xCenter <= x2 + radius) return true;
            }
            else {
                if (dsquare(xCenter, yCenter, x2, y1) <= rsq) return true;
            }
        }
        return false;
    }

    int dsquare(int x1, int y1, int x2, int y2) {
        return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    }
};
