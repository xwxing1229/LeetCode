// https://leetcode.cn/problems/camelcase-matching/

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n = queries.size(), m = pattern.size();
        vector<bool> res(n, true);
        for (int i = 0; i < n; ++i) {
            int j = 0;
            for (char ch: queries[i]) {
                if (j < m) {
                    if (ch == pattern[j]) {
                        j += 1;
                    }
                    else if (isupper(ch)) {
                        res[i] = false;
                        break;
                    }
                }
                else if (isupper(ch)) {
                    res[i] = false;
                    break;
                }
            }
            if (j != m) res[i] = false;
        }
        return res;
    }
};
