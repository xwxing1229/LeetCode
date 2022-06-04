// https://leetcode.cn/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        double res;
        long N = n;
        if (n >= 0) {
            res = myPowPositive(x, N);
        }
        else {
            res = 1. / myPowPositive(x, -N);
        }
        return res;
    }

    double myPowPositive(double x, long n) {
        if (n == 0) {
            return 1;
        }

        long index = n / 2;
        double rt = myPowPositive(x, index);
        if (n == 2 * index) {
            return rt * rt;
        }
        else {
            return rt * rt * x;
        }
    }
};
