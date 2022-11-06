// https://leetcode.cn/problems/goal-parser-interpretation/

class Solution {
public:
    string interpret(string command) {
        string res;
        int i = 0;
        while (i < command.size()) {
            if (command[i] == 'G') {
                res += 'G';
                i += 1;
            }
            else {
                if (command[i+1] == ')') {
                    res += 'o';
                    i += 2;
                }
                else {
                    res += "al";
                    i += 4;
                }
            }
        }
        return res;
    }
};
