// https://leetcode.cn/problems/largest-3-same-digit-number-in-string/

class Solution {
public:
    string largestGoodInteger(string num) {
        string res;
        int res_num = 0, cnt = 1;
        for (int i = 1; i < num.size(); ++i) {
            if (num[i] != num[i-1]) {
                cnt = 1;
                continue;
            }
            cnt += 1;
            if (cnt == 3 && stoi(num.substr(i-2, 3)) >= res_num) {
                res = num.substr(i-2, 3);
                res_num = stoi(res);
            }
        }
        return res;
    }
};
