// https://leetcode.cn/problems/longest-uncommon-subsequence-ii/

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size(), res = -1;
        for (int i = 0; i < n; ++i) {
            string s = strs[i];
            bool valid = true;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (isSubseq(strs[j], s)) {
                    valid = false;
                    break;
                }
            }
            if (valid) res = max(res, (int)s.size());
        }
        return res;
    }

    bool isSubseq(string s1, string s2) {
        int i2 = 0, n2 = s2.size();
        for (int i1 = 0; i1 < s1.size(); ++i1) {
            if (s1[i1] == s2[i2]) {
                i2 += 1;
            }
            if (i2 == n2) return true;
        }
        return false;
    }
};
