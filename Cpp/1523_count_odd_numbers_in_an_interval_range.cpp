// https://leetcode.cn/problems/count-odd-numbers-in-an-interval-range/

#include <iostream>

using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        int res = (high - low + 1) / 2;
        if (low % 2 && high % 2) res += 1;
        return res;
    }
};

int main() {
    Solution sol;
    int low = 3, high = 7;
    cout << sol.countOdds(low, high) << '\n';
    return 0;
}