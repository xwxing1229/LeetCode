// https://leetcode.cn/problems/repeated-substring-pattern/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int i = 1; i <= n/2; ++i) {
            if ((s[i] == s[0]) && (n % i == 0)) {
                string sub = s.substr(0,i); // size of sub is i
                int repeat = n/i, cnt = 1;
                for (int j = 1; j < repeat; ++j) {
                    if (sub == s.substr(j*i, i)) {
                        cnt += 1;
                    }
                    else {
                        break;
                    }
                }
                if (cnt == repeat) {
                    return true;
                }
            }
        }
        return false;
    }
};
