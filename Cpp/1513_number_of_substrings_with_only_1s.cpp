// https://leetcode.cn/problems/number-of-substrings-with-only-1s/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numSub(string s) {
        long res = 0;
        int mod = 1000000007;
        int cnt = 0; // number of valid substrings that end with current 1
        for (const char &ch: s) {
            if (ch == '1') {
                cnt += 1;
                res = (res + cnt) % mod;
            }
            else {
                cnt = 0;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "0110111";
    cout << sol.numSub(s) << '\n';
    return 0;
}