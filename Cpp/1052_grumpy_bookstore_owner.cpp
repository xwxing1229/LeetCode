// https://leetcode.cn/problems/grumpy-bookstore-owner/

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        vector<int> dp(n-minutes+1, 0);
        for (int i = 0; i < minutes; ++i) {
            dp[0] += customers[i];
        }
        for (int i = minutes; i < n; ++i) {
            if (grumpy[i] == 0) {
                dp[0] += customers[i];
            }
        }

        int res = dp[0];
        for (int i = 1; i <= n-minutes; ++i) {
            dp[i] = dp[i-1];
            if (grumpy[i-1] == 1) {
                dp[i] -= customers[i-1];
            }
            if (grumpy[i+minutes-1] == 1) {
                dp[i] += customers[i+minutes-1];
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
