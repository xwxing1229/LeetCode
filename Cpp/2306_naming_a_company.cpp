// https://leetcode.cn/problems/naming-a-company/

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<vector<string>> groups(26);
        for (auto &s: ideas) {
            groups[s[0] - 'a'].push_back(s.substr(1));
        }
        long long res = 0;
        for (int i = 0; i < 26; ++i) {
            unordered_set<string> seti(groups[i].begin(), groups[i].end());
            for (int j = 0; j < i; ++j) {
                int common = 0, ni = groups[i].size();
                for (auto &s: groups[j]) {
                    if (seti.find(s) != seti.end()) {
                        common += 1;
                    }
                }
                int nj = groups[j].size();
                res += (long long)2 * (ni - common) * (nj - common);
            }
        }
        return res;
    }
};
