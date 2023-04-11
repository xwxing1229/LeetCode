// https://leetcode.cn/problems/robot-bounded-in-circle/

class Solution {
public:
    bool isRobotBounded(string instructions) {
        pair<int, int> pos = {0, 0}, dir = {0, 1};
        for (char ch: instructions) {
            if (ch == 'G') {
                pos.first += dir.first;
                pos.second += dir.second;
            }
            else if (ch == 'L') {
                int tmp = dir.first;
                dir.first = -dir.second;
                dir.second = tmp;
            }
            else {
                int tmp = dir.first;
                dir.first = dir.second;
                dir.second = -tmp;
            }
        }
        if ((pos.first == 0 && pos.second == 0) || (!(dir.first == 0 && dir.second == 1))) {
            return true;
        }
        else {
            return false;
        }
    }
};
