// https://leetcode.cn/problems/remove-duplicate-letters/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> counts(26), check(26);
        for (char ch: s) {
            counts[ch-'a'] = counts[ch-'a'] + 1;
        }

        string res;
        for (char ch: s) {
            int idx = ch - 'a';
            if (!check[idx]) {
                while ((!res.empty()) && (res.back() > ch)) {
                    if (counts[res.back()-'a'] > 0) {
                        check[res.back()-'a'] = 0;
                        res.pop_back();
                    }
                    else {
                        break;
                    }
                }
                res.push_back(ch);
                check[idx] = 1;
            }
            counts[idx] = counts[idx] - 1;
        }
        return res;
    }
};
