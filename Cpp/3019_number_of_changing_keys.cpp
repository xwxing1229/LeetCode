// https://leetcode.cn/problems/number-of-changing-keys/
   
class Solution {
public:
    int countKeyChanges(string s) {
        int res = 0;
        char pre = tolower(s[0]);
        for (int i = 1; i < s.size(); ++i) {
            char cur = tolower(s[i]);
            if (cur != pre) res += 1;
            pre = cur;
        }
        return res;
    }
};
