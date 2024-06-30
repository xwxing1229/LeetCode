// https://leetcode.cn/problems/target-sum/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int s = 0;
        for (int num: nums) {
            s += num;
        }
        if (s < target || s < -target) {
            return 0;
        }
        // [-s, s] -> [0, 2s]
        int total = 2 * s + 1;
        vector<vector<int>> dp(nums.size(), vector<int>(total, 0));
        dp[0][nums[0] + s] += 1;
        dp[0][-nums[0] + s] += 1;
        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];
            for (int s_pre = 0; s_pre < total; ++s_pre) {
                int cnt = dp[i-1][s_pre];
                if (cnt > 0) {
                    dp[i][num + s_pre] += cnt;
                    dp[i][-num + s_pre] += cnt;
                }
            }
        }
        return dp.back()[target + s];
    }
};
