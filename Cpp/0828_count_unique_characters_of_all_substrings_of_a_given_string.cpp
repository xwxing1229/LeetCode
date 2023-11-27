// https://leetcode.cn/problems/count-unique-characters-of-all-substrings-of-a-given-string/

class Solution {
public:
    int uniqueLetterString(string s) {
        unordered_map<char, vector<int>> char_idxs;
        for (int i = 0; i < s.size(); ++i) {
            char_idxs[s[i]].push_back(i);
        }
        int res = 0;
        for (auto &&[_, idxs]: char_idxs) {
            idxs.insert(idxs.begin(), -1);
            idxs.push_back(s.size());
            for (int i = 1; i < idxs.size()-1; ++i) {
                res += (idxs[i] - idxs[i-1]) * (idxs[i+1] - idxs[i]);
            }
        }
        return res;
    }
};