// https://leetcode.cn/problems/minimum-difference-between-highest-and-lowest-of-k-scores/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = nums[k-1] - nums[0];
        int n = nums.size();
        for (int i = 0; i <= n-k; ++i) {
            res = min(res, nums[i+k-1] - nums[i]);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {9,4,1,7};
    int k = 2;
    cout << sol.minimumDifference(nums, k) << '\n';
    return 0;
}