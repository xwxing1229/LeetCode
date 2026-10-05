// https://leetcode.cn/problems/score-of-parentheses/

#include <string>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        int res = 0, depth = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                depth += 1;
            }
            else {
                depth -= 1;
                if (s[i-1] == '(') {
                    res += (1 << depth);
                }
            }
        }
        return res;
    }
};