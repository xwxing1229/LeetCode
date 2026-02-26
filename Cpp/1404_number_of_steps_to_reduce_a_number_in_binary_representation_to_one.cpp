// https://leetcode.cn/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int res = 0;
        int carry = 0;
        for (int i = s.size()-1; i > 0; --i) {
            int val = s[i] - '0' + carry;
            // even: +1 (/2), odd: +2 (+1 then /2)
            res += (val & 1) + 1;
            carry = val > 0;
        }
        return res + carry;
    }
};

int main() {
    Solution sol;
    string s = "1111011110000011100000110001011011110010111001010111110001";
    cout << sol.numSteps(s) << '\n';
    return 0;
}