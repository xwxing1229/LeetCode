// https://leetcode.cn/problems/complement-of-base-10-integer/

#include <iostream>

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int res = 0;
        int move = 0;
        while (n > 0) {
            int val = 1 - (n & 1);
            res = (val << move) + res;
            n >>= 1;
            move += 1;
        }
        return res;
    }
};

int main() {
    Solution sol;
    int n = 5;
    std::cout << sol.bitwiseComplement(n) << '\n';
    return 0;
}