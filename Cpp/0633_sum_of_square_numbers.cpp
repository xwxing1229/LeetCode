// https://leetcode.cn/problems/sum-of-square-numbers/

class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0, b = sqrt(c);
        while (a <= b) {
            long a_sq= a*a, b_sq = b*b;
            long sq_sum = a_sq + b_sq;
            if (sq_sum == c) {
                return true;
            }
            else if (sq_sum < c) {
                a = max(a+1, long(sqrt(c - b_sq)));
            }
            else {
                b = min(b-1, long(sqrt(c - a_sq)));
            }
        }
        return false;
    }
};


