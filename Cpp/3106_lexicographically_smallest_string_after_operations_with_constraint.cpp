// https://leetcode.cn/problems/lexicographically-smallest-string-after-operations-with-constraint/
        
class Solution {
public:
    string getSmallestString(string s, int k) {
        string res = s;
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            int move = 0;
            if ((ch - 'a' > 13) && ('z' - ch + 1 <= k)) {
                res[i] = 'a';
                move = 'z' - ch + 1;
            }
            else {
                move = min(ch-'a', k);
                res[i] = ch - move;
            }
            k -= move;
            if (k == 0) {
                break;
            }
        }
        return res;
    }
};
