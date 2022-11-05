// https://leetcode.cn/problems/parsing-a-boolean-expression/

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;
        for (char ch: expression) {
            if ((ch == ',') || (ch == '(')) continue;
            else if (ch == ')') {
                int cnt_t = 0, cnt_f = 0;
                while (!stk.empty()) {
                    char cur = stk.top();
                    stk.pop();
                    if (cur == 't') cnt_t += 1;
                    else if (cur == 'f') cnt_f += 1;
                    else if (cur == '&') {
                        if (cnt_f > 0) stk.push('f');
                        else stk.push('t');
                        break;
                    }
                    else if (cur == '|') {
                        if (cnt_t > 0) stk.push('t');
                        else stk.push('f');
                        break;
                    }
                    else {
                        if (cnt_t > 0) stk.push('f');
                        else stk.push('t');
                        break;
                    }
                }
            }
            else stk.push(ch);
        }
        
        if (stk.top() == 't') return true;
        else return false;
    }
};
