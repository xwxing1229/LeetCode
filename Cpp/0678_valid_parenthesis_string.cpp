// https://leetcode.cn/problems/valid-parenthesis-string/

#include <string>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        // mx: maximum number of unmatched "(".
        // mn: minimum number of unmatched "(".
        int mx = 0, mn = 0;
        for (char ch: s) {
            if (ch == '(') {
                mx += 1;
                mn += 1;
            }
            else if (ch == ')') {
                mx -= 1;
                mn -= 1;
                if (mx < 0) return false;
            }
            else {
                mx += 1;
                mn -= 1;
            }
            mn = max(mn, 0);
        }
        return mn == 0;
    }
};