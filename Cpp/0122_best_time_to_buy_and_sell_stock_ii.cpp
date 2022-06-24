// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int yesterday = prices[i-1], today = prices[i];
            if (yesterday < today) {
                res = res + today - yesterday;
            }
        }
        return res;
    }
};
