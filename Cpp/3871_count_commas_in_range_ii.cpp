// https://leetcode.cn/problems/count-commas-in-range-ii/

#include <algorithm>

using namespace std;

class Solution {
public:
    long long countCommas(long long n) {
        int cnt = 0;
        long long num = n;
        while (num > 0) {
            num /= 1000;
            cnt += 1;
        }
        long long res = 0;
        long long left = 1000;
        for (int c = 1; c < cnt; ++c) {
            long long tmp = left * 1000;
            long long right = min(tmp-1, n);
            res += (right - left + 1) * c;
            left = tmp;
        }
        return res;
    }
};