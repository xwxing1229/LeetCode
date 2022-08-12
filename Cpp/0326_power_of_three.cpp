// https://leetcode.cn/problems/power-of-three/

class Solution {
public:
    bool isPowerOfThree(int n) {
        /*
        if (n <= 0) {
            return false;
        }

        int rem = n % 3;
        while (rem == 0) {
            n = n / 3;
            rem = n % 3;
        }
        if (n == 1) {
            return true;
        }
        else {
            return false;
        }
        */

        // Check if n is a divisor of 3^19 which is the largest
        // integer in [-2^31, 2^31-1].
        if ((n > 0) && (1162261467 % n == 0)) {
            return true;
        }
        else {
            return false;
        }
    }
};
