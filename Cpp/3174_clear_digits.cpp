// https://leetcode.cn/problems/clear-digits/

class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        std::vector<bool> deleted(n, false);
        for (int i = 0; i < n; ++i) {
            char ch = s[i];
            if (isdigit(ch)) {
                deleted[i] = true;
                for (int j = i-1; j >= 0; --j) {
                    if (isalpha(s[j]) && !deleted[j]) {
                        deleted[j] = true;
                        break;
                    }
                }
            }
        }
        string res;
        for (int i = 0; i < n; ++i) {
            if (!deleted[i]) {
                res += s[i];
            }
        }
        return res;
    }
};
