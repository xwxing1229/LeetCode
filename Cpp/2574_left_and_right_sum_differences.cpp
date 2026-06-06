// https://leetcode.cn/problems/left-and-right-sum-differences/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> right(n, 0);
        for (int i = n-1; i > 0; --i) {
            right[i-1] = right[i] + nums[i];
        }
        vector<int> res(n);
        int left = 0;
        for (int i = 0; i < n; ++i) {
            res[i] = abs(left - right[i]);
            left += nums[i];
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10,4,8,3};
    auto res = sol.leftRightDifference(nums);
    for (const auto &val: res) cout << val << ", ";
    cout << '\n';
    return 0;
}