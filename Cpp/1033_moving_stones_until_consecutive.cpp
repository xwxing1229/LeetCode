// https://leetcode.cn/problems/moving-stones-until-consecutive/

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> pos = {a, b, c};
        sort(pos.begin(), pos.end());
        int min_move, max_move;
        if (pos[1] - pos[0] == 1) {
            if (pos[2] - pos[1] == 1) min_move = 0;
            else min_move = 1;
        }
        else if (pos[1] - pos[0] == 2) {
            min_move = 1;
        }
        else {
            if (pos[2] - pos[1] <= 2) min_move = 1;
            else min_move = 2;
        }
        max_move = pos[2] - pos[0] - 2;
        vector<int> res = {min_move, max_move};
        return res;
    }
};
