// https://leetcode.cn/problems/existence-of-a-substring-in-a-string-and-its-reverse/

class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_set<string> revs;
        for (int i = 0; i < s.size() - 1; ++i) {
            string sub = s.substr(i, 2);
            string sub_rev(sub);
            reverse(sub_rev.begin(), sub_rev.end());
            revs.insert(sub_rev);
            if (revs.find(sub) != revs.end()) {
                return true;
            }
        }
        return false;
    }
};