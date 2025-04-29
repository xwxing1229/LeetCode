// https://leetcode.cn/problems/count-good-numbers/

#include <iostream>

using namespace std;

class Solution {
public:
    int countGoodNumbers(long long n) {
        int mod = 1e9 + 7;
        return pow(5, (n+1)/2) * pow(4, n/2) % mod_;
    }

    long long pow(long long x, long long n) {
        long long res = 1;
        while (n) {
            if (n & 1) {
                res = res * x % mod_;
            }
            x = x * x % mod_;
            n >>= 1;
        }
        return res;
    }

    int mod_ {1000000007};
};

int main() {
    Solution sol;
    long long n = 4;
    cout << sol.countGoodNumbers(n) << '\n';
    return 0;
}
