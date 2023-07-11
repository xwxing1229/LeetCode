// https://leetcode.cn/problems/maximum-alternating-subsequence-sum/

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // dp[i].first:  maximum alternating sum until the ith element with the size
        //               of the corresponding subsequence even
        // dp[i].second: maximum alternating sum until the ith element with the size
        //               of the corresponding subsequence odd
        int n = nums.size();
        vector<pair<long long, long long>> dp(n);
        dp[0].second = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i].first = max(dp[i-1].first, dp[i-1].second-nums[i]);
            dp[i].second = max(dp[i-1].second, dp[i-1].first+nums[i]);
        }
        long long res = max(dp[n-1].first, dp[n-1].second);
        return res;
    }
};