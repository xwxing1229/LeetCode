// https://leetcode.cn/problems/base-7/

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        string tmp;
        int n = num, neg = 0;
        if (num < 0) {
            n = -num;
            neg = 1;
        }
        while (n) {
            tmp += (n % 7 + '0');
            n /= 7;
        }
        if (neg) {
            tmp += '-';
        }
        string res;
        for (int i = tmp.size()-1; i >= 0; --i) {
            res += tmp[i];
        }
        return res;
    }
};
