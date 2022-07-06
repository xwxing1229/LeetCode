// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // Based on #0123.
        int n = prices.size();
        k = min(k, n/2);
        if (k == 0) {
            return 0;
        }

        vector<int> buy_sell(2*k);
        for (int i = 0; i < k; ++i) {
            buy_sell[2*i] = -prices[0];
        }
        for (int price: prices) {
            buy_sell[0] = max(buy_sell[0], -price);
            for (int i = 1; i < 2*k; ++i) {
                if (i % 2 == 0) {
                    buy_sell[i] = max(buy_sell[i], buy_sell[i-1] - price);
                }
                else {
                    buy_sell[i] = max(buy_sell[i], price + buy_sell[i-1]);
                }
            }
        }
        return buy_sell[2*k-1];
    }
};
