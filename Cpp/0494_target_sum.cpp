// https://leetcode.cn/problems/target-sum/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int s = 0, n = nums.size();
        for (int num: nums) {
            s += num;
        }
        if (s < target || (s - target) % 2 != 0) {
            return 0;
        }
        int neg = (s - target) / 2;
        vector<int> dp(neg+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            int num = nums[i-1];
            for (int j = neg; j >= 0; --j) {
                if (j >= num) {
                    dp[j] += dp[j-num];
                }
            }
        }
        return dp[neg];
    }
};
