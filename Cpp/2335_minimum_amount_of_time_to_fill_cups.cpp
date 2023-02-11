// https://leetcode.cn/problems/minimum-amount-of-time-to-fill-cups/

class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        if (amount[0] + amount[1] <= amount[2]) return amount[2];
        else return (amount[0] + amount[1] + amount[2] + 1) / 2;
    }
};