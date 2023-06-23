// https://leetcode.cn/problems/maximum-value-of-a-string-in-an-array/

class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int res = 0;
        for (const string &s: strs) {
            bool isnum = true;
            int val = 0;
            for (char ch: s) {
                if (!isdigit(ch)) {
                    isnum = false;
                    break;
                }
                val = val * 10 + ch - '0';
            }
            if (isnum && val > res) res = val;
            else if (!isnum && s.size() > res) res = s.size();
        }
        return res;
    }
};