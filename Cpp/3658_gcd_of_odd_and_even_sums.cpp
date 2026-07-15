// https://leetcode.cn/problems/gcd-of-odd-and-even-sums/

#include <numeric>

using namespace std;

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd = n * n, even = odd + n;
        return gcd(odd, even);
    }
};