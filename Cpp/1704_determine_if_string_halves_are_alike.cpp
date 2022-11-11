// https://leetcode.cn/problems/determine-if-string-halves-are-alike/

class Solution {
public:
    bool halvesAreAlike(string s) {
        string vowels = "aeiouAEIOU";
        int n = s.size(), cnt = 0;
        for (int i = 0; i < n/2; ++i) {
            if (vowels.find(s[i]) != string::npos) {
                cnt += 1;
            }
        }
        for (int i = n/2; i < n; ++i) {
            if (vowels.find(s[i]) != string::npos) {
                cnt -= 1;
            }
        }
        bool res = false;
        if (cnt == 0) {
            res = true;
        }
        return res;
    }
};
