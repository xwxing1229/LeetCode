// https://leetcode.cn/problems/lexicographically-smallest-string-after-substring-operation/
        
class Solution {
public:
    string smallestString(string s) {
        int i = 0, n = s.size();
        while (i < n && s[i] == 'a') {
            i += 1;
        }
        if (i == n) {
            s[n-1] = 'z';
        }
        else {
            int start = i;
            while (i < n && s[i] != 'a') {
                i += 1;
            }
            for (int idx = start; idx < i; ++idx) {
                s[idx] -= 1;
            }
        }
        return s;
    }
};
