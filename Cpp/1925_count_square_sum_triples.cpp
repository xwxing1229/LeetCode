// https://leetcode.cn/problems/count-square-sum-triples/

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int countTriples(int n) {
        int res = 0;
        int n_sq = n * n;
        for (int a = 1; a <= n/1.4; ++a) {
            int a_sq = a * a;
            for (int b = a+1; b <= n; ++b) {
                int s = a_sq + b * b;
                if (s > n_sq) break;
                int s_sqrt = sqrt(s);
                res += (s_sqrt * s_sqrt == s);
            }
        }
        res *= 2;
        return res;
    }
};

int main() {
    Solution sol;
    int n = 10;
    cout << sol.countTriples(n) << '\n';
    return 0;
}