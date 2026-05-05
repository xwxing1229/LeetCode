// https://leetcode.cn/problems/minimum-changes-to-make-alternating-binary-string/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        auto StartFrom = [&s](char tar) {
            int res = 0;
            for (const auto &ch: s) {
                res += (ch != tar);
                tar = '1' - tar + '0';
            }
            return res;
        };

        return min(StartFrom('0'), StartFrom('1'));
    }
};

int main() {
    Solution sol;
    string s = "0100";
    cout << sol.minOperations(s) << '\n';
    return 0;
}