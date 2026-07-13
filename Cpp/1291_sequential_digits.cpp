// https://leetcode.cn/problems/sequential-digits/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        auto count = [](int num) {
            int res = 0;
            while (num > 0) {
                num /= 10;
                res += 1;
            }
            return res;
        };

        vector<int> res;
        int digits_low = count(low), digits_high = count(high);
        for (int digit = digits_low; digit <= digits_high; ++digit) {
            int curr = 0, d = 1, add = 0;
            for (int i = 0; i < digit; ++i) {
                curr = curr * 10 + d;
                d += 1;
                add = add * 10 + 1;
            }
            while (curr % 10 != 0 && curr <= high) {
                if (curr >= low) {
                    res.push_back(curr);
                }
                curr += add;
            }
        }
        return res;
    }
};