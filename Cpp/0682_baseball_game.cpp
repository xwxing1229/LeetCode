// https://leetcode.cn/problems/baseball-game/

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stk;
        int i = 0;
        for (auto &op: operations) {
            if (op == "C") stk.pop();
            else if (op == "D") stk.push(2 * stk.top());
            else if (op == "+") {
                int pre = stk.top();
                stk.pop();
                int pre_pre = stk.top();
                stk.push(pre);
                stk.push(pre + pre_pre);
            }
            else stk.push(stoi(op));
        }
        int res = 0;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};
