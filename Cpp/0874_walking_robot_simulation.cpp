// https://leetcode.cn/problems/walking-robot-simulation/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<int> obs;
        for (const auto &o: obstacles) {
            obs.insert(o[0] * 60001 + o[1]);
        }
        int res = 0;
        int px = 0, py = 0;
        int dx = 0, dy = 1;
        for (const auto &cmd: commands) {
            if (cmd == -2) {
                int tmp = dx;
                dx = -dy;
                dy = tmp;
            }
            else if (cmd == -1) {
                int tmp = dx;
                dx = dy;
                dy = -tmp;
            }
            else {
                for (int i = 0; i < cmd; ++i) {
                    int x = px + dx, y = py + dy;
                    if (obs.count(x * 60001 + y)) break;
                    px = x;
                    py = y;
                    res = max(res, px * px + py * py);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> commands = {4,-1,3};
    vector<vector<int>> obstacles = {};
    cout << sol.robotSim(commands, obstacles) << '\n';
    return 0;
}