// https://leetcode.cn/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> table{
            {'}', '{'}, {']', '['}, {')', '('}
        };
        stack<char> stk;

        for (char c: s) {
            auto iter = table.find(c);
            if (iter != table.end()) {
                if ((stk.empty()) || (stk.top() != table[c])) {
                    return false;
                }

                stk.pop();
            }
            else {
                stk.push(c);
            }
        }

        return stk.empty();
    }
};