// https://leetcode.cn/problems/sqrtx/

class Solution {
public:
    int mySqrt (int x) {
        int left = 0, right = x;
        int res;
        while (left <= right) {
            long mid = left + (right-left) / 2;
            long sq = mid * mid;
            
            if (sq <= x) {
                res = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }
};
