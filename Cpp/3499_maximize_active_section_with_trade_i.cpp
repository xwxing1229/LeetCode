// https://leetcode.cn/problems/maximize-active-section-with-trade-i/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size(), cnt = 0, cnt1 = 0;
        int prev0 = -n, cnt0_max = 0;
        for (int i = 0; i < n; ++i) {
            cnt += 1;
            // The end of a substring containing identical chars.
            if (i == n-1 || s[i] != s[i+1]) {
                if (s[i] == '1') {
                    cnt1 += cnt;
                }
                else {
                    cnt0_max = max(cnt0_max, prev0 + cnt);
                    prev0 = cnt;
                }
                cnt = 0;
            }
        }
        return cnt1 + cnt0_max;
    }
};

int main() {
    Solution sol;
    string s = "01";
    cout << sol.maxActiveSectionsAfterTrade(s) << '\n';
    return 0;
}