// https://leetcode.cn/problems/minimum-operations-to-make-array-sum-divisible-by-k/

#include <iostream>
#include <vector>

using namespace  std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int s = 0;
        for (int num: nums) s += num;
        return s % k;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,9,7};
    int k = 5;
    cout << sol.minOperations(nums, k) << '\n';
    return 0;
}