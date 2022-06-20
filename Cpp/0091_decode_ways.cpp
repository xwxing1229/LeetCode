// https://leetcode.cn/problems/decode-ways/

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }
        
        int res = 1, res_last = 1, res_last_last = 1;
        for (int i = 1; i < s.size(); ++i) {
            int num1 = s[i-1] - '0', num2 = s[i] - '0';
            int val = 10 * num1 + num2;
            
            if (num2 == 0) {
                if ((val == 0) || (val >= 30)) {
                    return 0;
                }
                else {
                    res = res_last_last;
                }
            }
            else {
                if ((val >= 11) && (val <= 26)) {
                    res = res_last_last + res_last;
                }
                else {
                    res = res_last;
                }
            }
            
            res_last_last = res_last;
            res_last = res;
        }
        
        return res;
    }
};
