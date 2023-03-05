// https://leetcode.cn/problems/license-key-formatting/

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res;
        int cnt = 0;
        for (int i = s.size()-1; i >= 0; --i) {
            if (s[i] == '-') continue;
            res += toupper(s[i]);
            cnt += 1;
            if (cnt == k) {
                res += '-';
                cnt = 0;
            }
        }
        if (res.back() == '-') {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
