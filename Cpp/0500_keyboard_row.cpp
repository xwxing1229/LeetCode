// https://leetcode.cn/problems/keyboard-row/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        unordered_map<int, unordered_set<char>> table{
            {0, unordered_set<char>{
                'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
                'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'}},
            {1, unordered_set<char>{
                'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
                'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'}},
            {2, unordered_set<char>{
                'z', 'x', 'c', 'v', 'b', 'n', 'm',
                'Z', 'X', 'C', 'V', 'B', 'N', 'M'}}
        };
        for (auto word: words) {
            int idx = 0;
            for (int i = 0; i < 3; ++i) {
                if (table[i].find(word[0]) != table[i].end()) {
                    idx = i;
                    break;
                }
            }
            bool can = true;
            for (char ch: word) {
                if (table[idx].find(ch) == table[idx].end()) {
                    can = false;
                    break;
                }
            }
            if (can) {
                res.push_back(word);
            }
        }
        return res;
    }
};
