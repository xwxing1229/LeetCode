// https://leetcode.cn/problems/greatest-sum-divisible-by-three/

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // dp[i][j]: maximum sum of elements chosen from nums[0], ..., nums[i-1] with
        //           sum % 3 = j.
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(3, -1));
        dp[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                int k = (3 + j - nums[i]%3) % 3;
                if (dp[i][k] >= 0) {
                    dp[i+1][j] = max(dp[i][j], dp[i][k] + nums[i]);
                }
                else {
                    dp[i+1][j] = dp[i][j];
                }
            }
        }
        return dp[n][0];
    }
};