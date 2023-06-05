// https://leetcode.cn/problems/swap-for-longest-repeated-character-substring/

class Solution {
public:
    int maxRepOpt1(string text) {
        unordered_map<char, int> cnt;
        for (char ch: text) {
            cnt[ch] += 1;
        }
        int i = 0, n = text.size();
        int res = 0;
        while (i < n) {
            char ch = text[i];
            int j = i + 1;
            while (j < n && text[j] == ch) {
                j += 1;
            }
            int k = j + 1;
            while (k < n && text[k] == ch) {
                k += 1;
            }
            res = max(res, min(k-i, cnt[ch]));

            i = j;
        }
        return res;
    }
};
