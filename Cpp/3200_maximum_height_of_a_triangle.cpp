// https://leetcode.cn/problems/maximum-height-of-a-triangle/

class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        return max(check(red, blue), check(blue, red));
    }

    int check(int first, int second) {
        int tmp1 = sqrt(first);
        int tmp2 = (sqrt(4*second+1) - 1) / 2;
        int res = tmp1 + tmp2;
        if (tmp1 < tmp2) {
            res = tmp1 + tmp1;
        }
        else if (tmp1 > tmp2 && tmp1 - tmp2 > 1) {
            res = tmp2 + tmp2 + 1;
        }
        return res;
    }
};
