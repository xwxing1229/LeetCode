// https://leetcode.cn/problems/check-balanced-string/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isBalanced(string num) {
        int s = 0, k = 1;
        for (char ch: num) {
            s += (ch - '0') * k;
            k *= -1;
        }
        return s == 0;
    }
};

int main() {
    Solution sol;
    string num = "1232";
    cout << sol.isBalanced(num) << '\n';
    return 0;
}
