// https://leetcode.cn/problems/maximum-number-of-balls-in-a-box/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> boxes(46, 0);
        for (int num = lowLimit; num <= highLimit; ++num) {
            int s = 0, cur = num;
            while (cur) {
                s += cur % 10;
                cur /= 10;
            }
            boxes[s] += 1;
        }
        int res = boxes[0];
        for (auto cnt: boxes) res = max(res, cnt);
        return res;
    }
};

int main() {
    Solution sol;
    int lowLimit = 5, highLimit = 15;
    int res = sol.countBalls(lowLimit, highLimit);
    cout << res << '\n';
    return 0;
}