// https://leetcode.cn/problems/maximum-total-subarray-value-i/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int min_ = nums[0], max_ = nums[0];
        for (const int &num: nums) {
            min_ = min(min_, num);
            max_ = max(max_, num);
        }
        return (long long)k * (max_ - min_);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,2};
    int k = 2;
    cout << sol.maxTotalValue(nums, k) << '\n';
    return 0;
}