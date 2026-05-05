// https://leetcode.cn/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int res = 0;
        for (const auto &ch: n) {
            res = max(res, ch - '0');
        }
        return res;
    }
};

int main() {
    Solution sol;
    string n = "27346209830709182346"; // 9
    cout << sol.minPartitions(n) << '\n';
    return 0;
}