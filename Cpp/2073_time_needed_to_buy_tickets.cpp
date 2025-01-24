// https://leetcode.cn/problems/time-needed-to-buy-tickets/

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res = tickets[k], val = tickets[k];
        for (int i = 0; i < k; ++i) {
            res += min(tickets[i], val);
        }
        for (int i = k+1; i < tickets.size(); ++i) {
            res += min(tickets[i], val-1);
        }
        return res;
    }
};
