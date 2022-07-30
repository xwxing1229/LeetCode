// https://leetcode.cn/problems/word-pattern/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words = split(s);
        if (pattern.size() != words.size()) {
            return false;
        }

        unordered_map<char, string> hash_ps;
        unordered_map<string, char> hash_sp;
        for (int i = 0; i < pattern.size(); ++i) {
            char p = pattern[i];
            string word = words[i];

            if ((hash_ps.find(p) == hash_ps.end()) &&
                ((hash_sp.find(word) == hash_sp.end()))) {
                hash_ps[p] = word;
                hash_sp[word] = p;
            }
            else if ((hash_ps.find(p) != hash_ps.end()) &&
                (hash_sp.find(word) != hash_sp.end())) {
                if ((hash_ps[p] != word) || (hash_sp[word] != p)) {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        return true;
    }

    vector<string> split(string s) {
        vector<string> res;
        string word;
        for (char c: s) {
            if (c == ' ') {
                res.push_back(word);
                word.clear();
            }
            else {
                word = word + c;
            }
        }
        res.push_back(word);
        return res;
    }
};
