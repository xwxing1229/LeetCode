// https://leetcode.cn/problems/determine-the-minimum-sum-of-a-k-avoiding-array/

#include <iostream>

using namespace std;
        
class Solution {
public:
    int minimumSum(int n, int k) {
        int half = k / 2;
        if (n <= half) {
            return (1 + n) * n / 2;
        }
        int res = (1 + half) * half / 2;
        res += (k + k + n - half - 1) * (n - half) / 2;
        return res;
    }
};

int main() {
    Solution sol;
    int n = 5, k = 4;
    cout << sol.minimumSum(n, k) << '\n';
    return 0;
}