// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp0: a stock is held
        // dp1: no stock is held, in freezing period
        // dp2: no stock is held, not in freezing period
        int dp0 = -prices[0], dp1 = 0, dp2 = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int dp0_pre = dp0, dp1_pre = dp1, dp2_pre = dp2;
            dp0 = max(dp0_pre, dp2_pre - prices[i]);
            dp1 = dp0_pre + prices[i];
            dp2 = max(dp1_pre, dp2_pre);
        }
        return max(dp1, dp2);
    }
};
