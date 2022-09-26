// https://leetcode.cn/problems/largest-divisible-subset/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        int max_size = 1, max_val = nums[0], max_idx = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[j]+1, dp[i]);
                }
            }
            if (dp[i] > max_size) {
                max_size = dp[i];
                max_val = nums[i];
                max_idx = i;
            }
        }

        vector<int> res = {};
        for (int i = max_idx; i >= 0; --i) {
            if ((max_val % nums[i] == 0) && (dp[i] == max_size)) {
                res.push_back(nums[i]);
                max_val = nums[i];
                max_size = max_size - 1;
            }
        }
        return res;
    }
};
