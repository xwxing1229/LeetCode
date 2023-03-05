// https://leetcode.cn/problems/maximum-profit-of-operating-a-centennial-wheel/

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        if (boardingCost * 4 <= runningCost) {
            return -1;
        }
        int res = -1, op = 0, waiting = 0, profit = 0, profit_max = 0;
        for (int customer: customers) {
            waiting += customer;
            int board = min(4, waiting);
            profit += (board * boardingCost - runningCost);
            op += 1;
            if (profit > profit_max) {
                res = op;
                profit_max = profit;
            }
            waiting -= board;
        }
        if (waiting > 4 || waiting * boardingCost > runningCost) {
            res = op + waiting / 4;
            waiting %= 4;
        }
        if (waiting * boardingCost > runningCost) {
            res += 1;
        }
        return res;
    }
};
