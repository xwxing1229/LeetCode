// https://leetcode.cn/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> hash_table;
        for (char ch: s) {
            hash_table[ch] = hash_table[ch] + 1;
        }
        for (char ch: t) {
            hash_table[ch] = hash_table[ch] - 1;
            if (hash_table[ch] < 0) {
                return false;
            }
        }
        return true;
    }
};
