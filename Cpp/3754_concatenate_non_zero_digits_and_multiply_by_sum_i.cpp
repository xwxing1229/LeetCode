// https://leetcode.cn/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/

#include <iostream>

using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0, s = 0, base = 1;
        while (n > 0) {
            int value = n % 10;
            x += value * base;
            s += value;
            base *= 1 + 9 * (value > 0);
            n /= 10;
        }
        return x * s;
    }
};

int main() {
    Solution sol;
    int n = 10203004;
    cout << sol.sumAndMultiply(n) << '\n';
    return 0;
}