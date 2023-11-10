// https://leetcode.cn/problems/find-the-longest-balanced-substring-of-a-binary-string/

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int res = 0;
        int start0 = 0, i = 0, n = s.size();
        while (i < n) {
            while (i < n && s[i] != '1') {
                i += 1;
            }
            if (i >= n) break;

            int zeros = i - start0, start1 = i;
            while (i < n && s[i] != '0') {
                i += 1;
            }
            res = max(res, 2*min(zeros, i-start1));
            start0 = i;
        }
        return res;
    }
};