// https://leetcode.cn/problems/counting-words-with-a-given-prefix/

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0, n = pref.size();
        for (string const &word: words) {
            if ((word.size() >= n) && (word.substr(0, n) == pref)) {
                res += 1;
            }
        }
        return res;
    }
};
