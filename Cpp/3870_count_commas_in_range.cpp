// https://leetcode.cn/problems/count-commas-in-range/

#include <algorithm>

using namespace std;

class Solution {
public:
    int countCommas(int n) {
        int cnt = 0, num = n;
        while (num > 0) {
            num /= 1000;
            cnt += 1;
        }
        int res = 0;
        int left = 1000;
        for (int c = 1; c < cnt; ++c) {
            int tmp = left * 1000;
            int right = min(tmp-1, n);
            res += (right - left + 1) * c;
            left = tmp;
        }
        return res;
    }
};