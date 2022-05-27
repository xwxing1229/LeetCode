// https://leetcode.cn/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        string res = "", res_last = countAndSay(n-1);
        char cur = res_last[0];
        int cnt = 1;
        for (int i = 1; i < res_last.size(); ++i) {
            if (cur == res_last[i]) {
                cnt = cnt + 1;
            }
            else {
                res = res + to_string(cnt) + cur;
                cur = res_last[i];
                cnt = 1;
            }
        }
        res = res + to_string(cnt) + cur;
        return res;
    }
};
