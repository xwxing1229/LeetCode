// https://leetcode.cn/problems/remove-outermost-parentheses/

#include <string>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int cnt = 0, left = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                cnt += 1;
            }
            else {
                cnt -= 1;
                if (cnt == 0) {
                    res += s.substr(left+1, i-left-1);
                    left = i + 1;
                }
            }
        }
        return res;
    }
};