// https://leetcode.cn/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int res = n;
        // cnt0: number of chars that match "010101...".
        // cnt1: number of chars that match "101010...".
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n+n-1; ++i) {
            int num = s[i%n] - '0';
            if (num == min(i, n-1) % 2) cnt0 += 1;
            else cnt1 += 1;
            if (i >= n-1) {
                res = min(res, min(cnt0, cnt1));
                if (s[i-(n-1)] == '0') cnt0 -= 1;
                else cnt1 -= 1;
                cnt0 = cnt1;
                cnt1 = n - 1 - cnt0;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "111000";
    cout << sol.minFlips(s) << '\n';
    return 0;
}