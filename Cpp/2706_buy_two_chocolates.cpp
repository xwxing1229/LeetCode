// https://leetcode.cn/problems/buy-two-chocolates/
        
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int a = min(prices[0], prices[1]);
        int b = max(prices[0], prices[1]);
        for (int i = 2; i < prices.size(); ++i) {
            int price = prices[i];
            if (a > price) {
                b = min(b, a);
                a = price;
            }
            else {
                b = min(b, price);
            }
        }
        int tmp = a + b;
        if (tmp <= money) return money-tmp;
        else return money;
    }
};