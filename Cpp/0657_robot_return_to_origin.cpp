// https://leetcode.cn/problems/robot-return-to-origin/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int h = 0, v = 0;
        for (const auto &ch: moves) {
            if (ch == 'R') h += 1;
            else if (ch == 'L') h -= 1;
            else if (ch == 'D') v += 1;
            else v -= 1;
        }
        return h == 0 && v == 0;
    }
};

int main() {
    Solution sol;
    std::string moves = "UD";
    cout << sol.judgeCircle(moves) << '\n';
    return 0;
}