// https://leetcode.cn/problems/count-the-number-of-consistent-strings/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = words.size();
        vector<int> table(26, 0);
        for (char ch: allowed) {
            table[ch - 'a'] = 1;
        }
        for (string& word: words) {
            for (char ch: word) {
                if (table[ch - 'a'] == 0) {
                    res -= 1;
                    break;
                }
            }
        }
        return res;
    }
};
