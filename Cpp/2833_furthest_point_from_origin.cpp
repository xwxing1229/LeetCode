// https://leetcode.cn/problems/furthest-point-from-origin/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0, right = 0, tmp = 0;
        for (const char &ch: moves) {
            left += (ch == 'L');
            right += (ch == 'R');
            tmp += (ch == '_');
        }
        return max(left+tmp-right, right+tmp-left);
    }
};

int main() {
    Solution sol;
    string moves = "L_RL__R";
    cout << sol.furthestDistanceFromOrigin(moves) << '\n';
    return 0;
}