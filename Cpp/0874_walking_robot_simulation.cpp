// https://leetcode.cn/problems/walking-robot-simulation/

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<int> obs;
        for (auto &o: obstacles) {
            obs.insert(o[0] + o[1] * 60001);
        }
        int res = 0, px = 0, py = 0, dx = 0, dy = 1;
        for (auto command: commands) {
            if (command == -2) {
                int tmp = dx;
                dx = -dy;
                dy = tmp;
            }
            else if (command == -1) {
                int tmp = dx;
                dx = dy;
                dy = -tmp;
            }
            else {
                for (int i = 0; i < command; ++i) {
                    int x = px + dx, y = py + dy;
                    if (obs.find(x + y * 60001) != obs.end()) {
                        break;
                    }
                    px = x;
                    py = y;
                    int tmp = px * px + py * py;
                    if (tmp > res) {
                        res = tmp;
                    }
                }
            }
        }
        return res;
    }
};