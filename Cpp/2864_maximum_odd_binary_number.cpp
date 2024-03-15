// https://leetcode.cn/problems/maximum-odd-binary-number/

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt1 = 0, n = s.size();
        for (auto ch: s) {
            if (ch == '1') cnt1 += 1;
        }
        if (cnt1 <= 1) {
            return string(n-cnt1, '0') + string(cnt1, '1');
        }
        else {
            return string(cnt1-1, '1') + string(n-cnt1, '0') + string(1, '1');
        }
    }
};
