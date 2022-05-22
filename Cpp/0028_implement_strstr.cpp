// https://leetcode.cn/problems/implement-strstr/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n_h = haystack.size(), n_n = needle.size();
        if (n_n == 0) {
            return 0;
        }
        for (int i = 0; i <= n_h - n_n; ++i) {
            if (haystack.substr(i, n_n) == needle) {
                return i;
            }
        }
        return -1;
    }
};