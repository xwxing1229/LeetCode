// https://leetcode.cn/problems/construct-the-rectangle/

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int width = sqrt(area);
        while (area % width != 0) {
            width -= 1;
        }
        vector<int> res = {area/width, width};
        return res;
    }
};
