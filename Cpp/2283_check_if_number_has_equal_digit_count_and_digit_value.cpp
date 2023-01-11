// https://leetcode.cn/problems/check-if-number-has-equal-digit-count-and-digit-value/

class Solution {
public:
    bool digitCount(string num) {
        vector<int> cnt(10, 0);
        for (char ch: num) {
            cnt[ch-'0'] += 1;
        }
        for (int i = 0; i < num.size(); ++i) {
            if (num[i]-'0' != cnt[i]) {
                return false;
            }
        }
        return true;
    }
};
