// https://leetcode.cn/problems/rotated-digits/

#include <iostream>

using namespace std;

class Solution {
public:
    int rotatedDigits(int n) {
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            int num = i;
            bool all_valid = true, has_diff = false;
            while (num > 0) {
                int digit = num % 10;
                if (digit == 3 || digit == 4 || digit == 7) {
                    all_valid = false;
                    break;
                }
                else if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                    has_diff = true;
                }
                num /= 10;
            }
            if (all_valid && has_diff) {
                res += 1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.rotatedDigits(10) << '\n';
    return 0;
}