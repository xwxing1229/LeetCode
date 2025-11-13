// https://leetcode.cn/problems/maximum-number-of-operations-to-move-ones-to-the-end/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int maxOperations(string s) {
        int res = 0, move = 0;
        for (int i = s.size()-2; i >= 0; --i) {
            if (s[i] == '1') {
                if (s[i+1] == '0') {
                    move += 1;
                }
                res += move;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "1001101";
    cout << sol.maxOperations(s) << '\n';
    return 0;
}