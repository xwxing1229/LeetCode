// https://leetcode.cn/problems/prime-in-diagonal/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        auto is_prime = [](int num) {
            for (int x = 2; x*x <= num; ++x) {
                if (num % x == 0) return false;
            }
            return num > 1;
        };

        int res = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            int num1 = nums[i][i], num2 = nums[i][n-1-i];
            if (is_prime(num1) && num1 > res) res = num1;
            if (is_prime(num2) && num2 > res) res = num2;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> nums = {
        {1,2,3},
        {5,6,7},
        {9,10,11}
    };
    cout << sol.diagonalPrime(nums) << '\n';
    return 0;
}