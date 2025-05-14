// https://leetcode.cn/problems/total-characters-in-string-after-transformations-i/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int mod = 1000000007;
        vector<long long> cnt(26, 0);
        for (const auto &ch: s) {
            cnt[ch - 'a'] += 1;
        }
        for (int k = 0; k < t; ++k) {
            auto cnt_z = cnt[25];
            for (int i = 25; i > 1; --i) {
                cnt[i] = cnt[i-1];
            }
            cnt[1] = (cnt[0] + cnt_z) % mod;
            cnt[0] = cnt_z;
        }
        int res = 0;
        for (const auto &val: cnt) {
            res = (val + res) % mod;
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "abcyy";
    int t = 2;
    cout << sol.lengthAfterTransformations(s, t) << '\n';
    return 0;
}
