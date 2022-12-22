// https://leetcode.cn/problems/maximize-score-after-n-operations/

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                g[i][j] = gcd(nums[i], nums[j]);
            }
        }
        int total = 1 << n;
        vector<int> dp(total);
        for (int k = 0; k < (total); ++k) {
            int cnt = __builtin_popcount(k);
            if (cnt % 2 == 0) {
                for (int i = 0; i < n; ++i) {
                    if ((k >> i) & 1) {
                        for (int j = i+1; j < n; ++j) {
                            if ((k >> j) & 1) {
                                dp[k] = max(dp[k], dp[k^(1<<i)^(1<<j)] + cnt / 2 * g[i][j]);
                            }
                        }
                    }
                }
            }
        }
        return dp[total-1];
    }
};
