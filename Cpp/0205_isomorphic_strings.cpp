// https://leetcode.cn/problems/isomorphic-strings/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int ns = s.size(), nt = t.size();
        if (ns != nt) {
            return false;
        }

        unordered_map<char, char> s2t, t2s;
        for (int i = 0; i < ns; ++i) {
            char si = s[i], ti = t[i];
            if (((s2t.find(si) != s2t.end()) && (s2t[si] != ti)) ||
                ((t2s.find(ti) != t2s.end()) && (t2s[ti] != si))) {
                return false;
            }
            s2t[si] = ti;
            t2s[ti] = si;
        }
        return true;
    }
};
