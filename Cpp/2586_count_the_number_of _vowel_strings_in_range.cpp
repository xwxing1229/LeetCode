// https://leetcode.cn/problems/count-the-number-of-vowel-strings-in-range/

class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int res = 0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (int i = left; i <= right; ++i) {
            if (vowels.find(words[i][0]) != vowels.end() &&
                vowels.find(words[i].back()) != vowels.end()) {
                res += 1;
            }
        }
        return res;
    }
};