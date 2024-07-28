// https://leetcode.cn/problems/minimum-operations-to-make-a-special-number/

class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        int res = n;
        vector<string> possible = {"00", "25", "50", "75"};
        for (auto &s: possible) {
            int i = n-1;
            while (i >= 0 && num[i] != s[1]) {
                i -= 1;
            }
            i -= 1;
            while (i >= 0 && num[i] != s[0]) {
                i -= 1;
            }
            if (i >= 0) {
                res = min(res, n-i-2);
            }
        }
        for (char ch: num) {
            if (ch == '0') {
                res = min(res, n-1);
            }
        }
        return res;
    }
};
