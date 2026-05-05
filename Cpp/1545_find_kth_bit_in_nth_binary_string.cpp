// https://leetcode.cn/problems/find-kth-bit-in-nth-binary-string/

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';

        int mid = pow(2, n-1);
        if (k == mid) return '1';
        else if (k < mid) return findKthBit(n-1, k);
        else return '1' - findKthBit(n-1, 2*mid-k) + '0';
    }
};

int main() {
    Solution sol;
    int n = 4;
    int k = 11;
    cout << sol.findKthBit(n, k) << '\n';
    return 0;
}