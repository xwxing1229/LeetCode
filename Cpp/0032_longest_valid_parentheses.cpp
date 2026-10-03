// https://leetcode.cn/problems/longest-valid-parentheses/

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            }
            else if (stk.size() > 1) {
                stk.pop();
                res = max(res, i - stk.top());
            }
            else {
                stk.top() = i;
            }
        }
        return res;
    }
};