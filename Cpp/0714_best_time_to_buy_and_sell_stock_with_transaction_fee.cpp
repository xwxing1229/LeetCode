// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // dp0: maximum profit with 0 stock held
        // dp1: maximum profit with 1 stock held
        int dp0 = 0, dp1 = -prices[0];
        int dp0_pre = dp0, dp1_pre = dp1;
        for (int i = 1; i < prices.size(); ++i) {
            int cur = prices[i];
            dp0 = max(dp0_pre, dp1_pre + cur - fee);
            dp1 = max(dp1_pre, dp0_pre - cur);
            dp0_pre = dp0;
            dp1_pre = dp1;
        }
        return dp0;
    }
};
