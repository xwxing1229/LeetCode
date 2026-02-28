// https://leetcode.cn/problems/concatenation-of-consecutive-binary-numbers/

#include <iostream>

class Solution {
public:
    int concatenatedBinary(int n) {
        long long res = 0;
        int mod = 1e9 + 7;
        int shift = 0;
        for (int num = 1; num <= n; ++num) {
            // num = 2 ^ k
            if ((num & (num - 1)) == 0) {
                shift += 1;
            }
            res = ((res << shift) + num) % mod;
        }
        return static_cast<int>(res);
    }
};

int main() {
    Solution sol;
    int n = 12; // 505379714
    std::cout << sol.concatenatedBinary(n) << '\n';
    return 0;
}