// https://leetcode.cn/problems/reformat-phone-number/

class Solution {
public:
    string reformatNumber(string number) {
        string digits;
        for (char ch: number) {
            if (isdigit(ch)) {
                digits = digits + ch;
            }
        }
        string res;
        int n = digits.size(), idx = 0;
        while (idx < n) {
            if (n - idx == 4) {
                res = res + digits.substr(idx,2) + '-' + digits.substr(idx+2,2);
                break;
            }
            else if (n - idx == 2) {
                res = res + digits.substr(idx,2);
                break;
            }
            else {
                res = res + digits.substr(idx,3);
                if (n - idx > 3) {
                    res = res + '-';
                }
                idx = idx + 3;
            }
        }
        return res;
    }
};
