// https://leetcode.cn/problems/longest-palindrome/

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> cnt;
        for (char ch: s) {
            cnt[ch] = cnt[ch] + 1;
        }

        int res = 0, odd = 0;
        for (auto it = cnt.begin(); it != cnt.end(); ++it) {
            int count = it->second;
            res = res + count / 2 * 2;
        }
        if (res < s.size()) {
            res = res + 1;
        }
        return res;
    }
};
