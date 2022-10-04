// https://leetcode.cn/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int k = 0, n = t.size();
        for (char ch: s) {
            while ((k < n) && (ch != t[k])) {
                k = k + 1;
            }
            if (k >= n) {
                return false;
            }
            
            k = k + 1;
        }
        return true;
    }
};
