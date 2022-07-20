// https://leetcode.cn/problems/basic-calculator-ii/

class Solution {
public:
    int calculate(string s) {
        vector<int> stk;
        int n = s.size(), num = 0;
        char preOp = '+';
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                int tmp = s[i] - '0';
                num = 10 * num + tmp;
            }
            if ((i == n-1) || ((s[i] != ' ') && (!isdigit(s[i])))) {
                switch (preOp) {
                    case '+':
                        stk.push_back(num);
                        break;
                    case '-':
                        stk.push_back(-num);
                        break;
                    case '*':
                        stk.back() = stk.back() * num;
                        break;
                    default:
                        stk.back() = stk.back() / num;
                }
                num = 0;
                preOp = s[i];
            }
        }

        int res = 0;
        for (int val: stk) {
            res = res + val;
        }
        return res;
    }
};
