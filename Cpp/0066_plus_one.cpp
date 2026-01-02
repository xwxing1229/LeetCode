// https://leetcode.cn/problems/plus-one/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int n = digits.size();
        for (int i = n-1; i >= 0; --i) {
            int val = digits[i] + carry;
            digits[i] = val % 10;
            carry = val / 10;
            if (carry == 0) break;
        }
        if (carry) {
            digits.emplace(digits.begin(), 1);
        }
        return digits;
    }
};

int main() {
    Solution sol;
    vector<int> digits = {9,9};
    auto res = sol.plusOne(digits);
    for (auto val: res) cout << val << ", ";
    cout << '\n';
    return 0;
}