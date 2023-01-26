// https://leetcode.cn/problems/smallest-string-with-a-given-numeric-value/

class Solution {
public:
    string getSmallestString(int n, int k) {
        string res;
        int cur = n;
        for (int i = 0; i < n; ++i) {
            int diff = k - cur;
            if (diff > 25) {
                res += 'z';
                cur += 25;
            }
            else {
                res += ('a' + diff);
                string tmp(n-i-1, 'a');
                res += tmp;
                break;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
