// https://leetcode.cn/problems/number-of-orders-in-the-backlog/

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> buys;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> sells;
        for (auto const &order: orders) {
            int price = order[0], n = order[1];
            if (order[2] == 0) {
                while ((n > 0) && (!sells.empty()) && (sells.top().first <= price)) {
                    pair<int,int> sell = sells.top();
                    sells.pop();
                    if (n >= sell.second) {
                        n -= sell.second;
                    }
                    else {
                        sell.second -= n;
                        sells.push(sell);
                        n = 0;
                    }
                }
                if (n > 0) {
                    buys.push(make_pair(price, n));
                }
            }
            else {
                while ((n > 0) && (!buys.empty()) && (buys.top().first >= price)) {
                    pair<int,int> buy = buys.top();
                    buys.pop();
                    if (n >= buy.second) {
                        n -= buy.second;
                    }
                    else {
                        buy.second -= n;
                        buys.push(buy);
                        n = 0;
                    }
                }
                if (n > 0) {
                    sells.push(make_pair(price, n));
                }
            }
        }
        int res = 0;
        while (!buys.empty()) {
            res = (res + buys.top().second) % 1000000007;
            buys.pop();
        }
        while (!sells.empty()) {
            res = (res + sells.top().second) % 1000000007;
            sells.pop();
        }
        return res;
    }
};