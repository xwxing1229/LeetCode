// https://leetcode.cn/problems/find-maximum-number-of-string-pairs/

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int res = 0;
        unordered_set<string> s;
        for (auto &word: words) {
            string word_reverse = string(word.rbegin(), word.rend());
            if (s.find(word_reverse) != s.end()) {
                res += 1;
            }
            else {
                s.insert(word);
            }
        }
        return res;
    }
};
