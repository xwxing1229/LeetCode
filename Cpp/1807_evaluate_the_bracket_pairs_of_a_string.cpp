// https://leetcode.cn/problems/evaluate-the-bracket-pairs-of-a-string/

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> table;
        for (auto const &kv: knowledge) {
            table[kv[0]] = kv[1];
        }
        string res, key;
        for (char ch: s) {
            if (ch == ')') {
                if (table.find(key.substr(1, key.size()-1)) != table.end()) {
                    res += table[key.substr(1, key.size()-1)];
                }
                else {
                    res += '?';
                }
                key.clear();
            }
            else if ((ch == '(') || (key.size())) {
                key += ch;
            }
            else {
                res += ch;
            }
        }
        return res;
    }
};
