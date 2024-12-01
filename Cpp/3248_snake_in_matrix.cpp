// https://leetcode.cn/problems/snake-in-matrix/

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i = 0, j = 0;
        for (auto &cmd: commands) {
            if (cmd == "UP") i -= 1;
            else if (cmd == "DOWN") i += 1;
            else if (cmd == "LEFT") j -= 1;
            else j += 1;
        }
        int res = i * n + j;
        return res;
    }
};
