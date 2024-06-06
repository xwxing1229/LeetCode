// https://leetcode.cn/problems/separate-black-and-white-balls/
        
class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size(), i = 0, j = -1;
        long long res = 0;
        while (i < n && j < n) {
            while (i < n && s[i] == '0') {
                i += 1;
            }
            if (j < 0) {
                j = i + 1;
            }
            while (j < n && s[j] == '1') {
                j += 1;
            }
            if (j < n) {
                res += j - i;
                s[i] = '0';
                s[j] = '1';
            }
            i += 1;
            j += 1;
        }
        return res;
    }
};
