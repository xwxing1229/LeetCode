// https://leetcode.cn/problems/count-the-number-of-substrings-with-dominant-ones/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        vector<int> pos0 = {-1};
        int cnt1 = 0; // number of 1 in [0, right]
        for (int right = 0; right < s.size(); ++right) {
            if (s[right] == '0') {
                pos0.push_back(right);
            }
            else {
                res += right - pos0.back(); // substring s[~, right] that only contains `
                cnt1 += 1;
            }

            int n = pos0.size();
            for (int i = n-1; i > 0; --i) {
                int cnt0 = n - i; // number of 0 in [pos0[i], right]
                int cnt0_sq = cnt0 * cnt0;
                if (cnt0_sq > cnt1) break;
                int pre = pos0[i-1], cur = pos0[i];
                int cnt1_sub = right - cur + 1 - cnt0; // number of 1 in [pos0[i], right]
                int valid = cur - pre; // if cnt0 * cnt0 <= cnt1_sub
                if (cnt0_sq > cnt1_sub) {
                    valid = max(cur-pre-(cnt0_sq-cnt1_sub), 0);
                }
                res += valid;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "00011";
    cout << sol.numberOfSubstrings(s) << '\n';
    return 0;
}