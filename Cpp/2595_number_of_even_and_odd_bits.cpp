// https://leetcode.cn/problems/number-of-even-and-odd-bits/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> res(2, 0);
        int idx = 0;
        while (n) {
            res[idx] += (n & 1);
            n >>= 1;
            idx = 1 - idx;
        }
        return res;
    }
};

int main() {
    Solution sol;
    int n = 17;
    auto res = sol.evenOddBit(n);
    for (auto val: res) cout << val << ", ";
    cout << '\n';
    return 0;
}