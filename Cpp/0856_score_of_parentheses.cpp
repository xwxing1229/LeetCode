// https://leetcode.cn/problems/score-of-parentheses/

class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int> record;
        int idx = -1;
        for (char ch: s) {
            if (ch == '(') {
                record.push_back(0);
                idx = idx + 1;
            }
            else {
                if (record[idx] == 0) {
                    record[idx] = 1;
                }
                else {
                    int tmp = 0;
                    while ((idx >= 0) && (record[idx] != 0)) {
                        tmp = tmp + record[idx];
                        record.pop_back();
                        idx = idx - 1;
                    }
                    if ((idx >= 0) && (record[idx] == 0)) {
                        record[idx] = 2 * tmp;
                    }
                }
            }
        }
        int res = 0;
        for (int i: record) {
            res = res + i;
        }
        return res;
    }
};
