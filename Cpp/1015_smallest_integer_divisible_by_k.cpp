// https://leetcode.cn/problems/smallest-integer-divisible-by-k/

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int res = 1, rem = 1 % k;
        vector<int> check(k, 0);
        while (rem != 0) {
            res += 1;
            check[rem] = 1;
            rem = (rem * 10 + 1) % k;
            if (check[rem] == 1) {
                return -1;
            }
        }
        return res;
    }
};
