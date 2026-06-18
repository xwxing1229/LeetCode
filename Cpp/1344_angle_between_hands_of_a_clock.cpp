// https://leetcode.cn/problems/angle-between-hands-of-a-clock/

#include <iostream>

using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = ((double)minutes / 60 + hour) * 5;
        double res = abs(h - minutes) * 6;
        return res <= 180 ? res : 360 - res;
    }
};

int main() {
    Solution sol;
    int hour = 3;
    int minutes = 15;
    cout << sol.angleClock(hour, minutes) << '\n';
    return 0;
}