// https://leetcode.cn/problems/count-number-of-homogenous-substrings/

class Solution {
public:
    int countHomogenous(string s) {
        long res = 0, cnt = 1;
        s += ' ';
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i-1]) {
                cnt += 1;
            }
            else {
                res = (res + (1 + cnt) * cnt / 2) % 1000000007;
                cnt = 1;
            }
        }
        return res;
    }
};