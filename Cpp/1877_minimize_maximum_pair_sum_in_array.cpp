// https://leetcode.cn/problems/minimize-maximum-pair-sum-in-array/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums.back(), n = nums.size();
        for (int i = 0; i < n/2; ++i) {
            res = max(res, nums[i] + nums[n-1-i]);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,5,2,3};
    cout << sol.minPairSum(nums) << '\n';
    return 0;
}