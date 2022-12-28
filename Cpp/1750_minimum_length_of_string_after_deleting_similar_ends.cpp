// https://leetcode.cn/problems/minimum-length-of-string-after-deleting-similar-ends/

class Solution {
public:
    int minimumLength(string s) {
        int n = s.size(), l = 0, r = n-1;
        while (l < r) {
            if (s[l] != s[r]) return r - l + 1;
            while ((l + 1 < n) && (s[l+1] == s[l])) l += 1;
            while ((r - 1 > l) && (s[r-1] == s[r])) r -= 1;
            if (l == r) return 0;
            else {
                l += 1;
                r -= 1;
            }
        }
        return 1;
    }
};
