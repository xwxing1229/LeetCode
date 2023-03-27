// https://leetcode.cn/problems/count-substrings-that-differ-by-one-character/

class Solution {
public:
    int countSubstrings(string s, string t) {
        int res = 0;
        int m = s.size(), n = t.size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int diff = 0;
                for (int k = 0; k < min(m-i, n-j); ++k) {
                    if (s[i+k] != t[j+k]) {
                        diff += 1;
                    }
                    if (diff == 1) {
                        res += 1;
                    }
                    else if (diff > 1) {
                        break;
                    }
                }
            }
        }
        return res;
    }
};
