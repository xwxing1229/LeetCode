// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, min_stock = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            res = max(res, prices[i] - min_stock);
            min_stock = min(min_stock, prices[i]);
        }
        return res;
    }
};
