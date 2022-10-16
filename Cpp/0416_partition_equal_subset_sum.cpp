// https://leetcode.cn/problems/partition-equal-subset-sum/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // dp[i][j] = true: it is possible to construct a sublist (can be empty) from
        // {nums[0], nums[1], ..., nums[i]} such that the sum of this sublist is j.

        // Space complexity can be easily optimized since dp[i] only depends on dp[i-1].

        int s = 0, max_num = 0;
        for (int num: nums) {
            s = s + num;
            if (num > max_num) {
                max_num = num;
            }
        }
        if (s % 2 != 0) return false;
        int tar = s / 2, n = nums.size();
        if (max_num > tar) return false;

        vector<vector<bool>> dp(n, vector<bool>(tar+1, false));
        for (int i = 0; i < n; ++i) {
            dp[i][0] = true;
            dp[i][nums[i]] = true;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < tar+1; ++j) {
                if (j >= nums[i]) {
                    dp[i][j] = dp[i-1][j-nums[i]] || dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n-1][tar];
    }
};
