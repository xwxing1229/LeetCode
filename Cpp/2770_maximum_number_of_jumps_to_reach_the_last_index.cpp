// https://leetcode.cn/problems/maximum-number-of-jumps-to-reach-the-last-index/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = nums[i] - nums[j];
                if (-target <= diff && diff <= target && dp[j] >= 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        return dp.back();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,6,4,1,2};
    int target = 2;
    cout << sol.maximumJumps(nums, target) << '\n';
    return 0;
}