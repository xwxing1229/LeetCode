// https://leetcode.cn/problems/masking-personal-information/

class Solution {
public:
    string maskPII(string s) {
        string res;
        if (isalpha(s[0])) {
            res += tolower(s[0]);
            res += "*****";
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == '@') {
                    res += tolower(s[i-1]);
                    for (int j = i; j < s.size(); ++j) {
                        res += tolower(s[j]);
                    }
                    break;
                }
            }
        }
        else {
            string nums;
            for (char ch: s) {
                if (isdigit(ch)) {
                    nums += ch;
                }
            }
            int n = nums.size();
            if (n > 10) {
                res += ('+' + string(n-10, '*') + '-');
            }
            res += (string(3,'*') + '-' + string(3,'*') + '-' + nums.substr(n-4,'*'));
        }
        return res;
    }
};