// https://leetcode.cn/problems/minimum-array-end/

class Solution {
public:
    long long minEnd(int n, int x) {
        long long res = x, n_1 = n - 1;
        int i = 0, j = 0;
        while (n_1 >> j) {
            // The value at the ith position of x is 0.
            if (((res >> i) & 1) == 0) {
                // Put the value at the jth position of n-1 here.
                res |= (((n_1 >> j) & 1) << i);
                j += 1;
            }
            i += 1;
        }
        return res;
    }
};
