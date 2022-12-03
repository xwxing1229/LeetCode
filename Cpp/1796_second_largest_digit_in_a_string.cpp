// https://leetcode.cn/problems/second-largest-digit-in-a-string/

class Solution {
public:
    int secondHighest(string s) {
        int res = -1, max_ = -1;
        for (char ch: s) {
            if (isdigit(ch)) {
                int num = ch - '0';
                if (num > max_) {
                    res = max_;
                    max_ = num;
                }
                else if ((num < max_) && (num > res)) {
                    res = num;
                }
            }
        }
        return res;
    }
};
