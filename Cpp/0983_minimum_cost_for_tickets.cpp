// https://leetcode.cn/problems/minimum-cost-for-tickets/

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.back()+1, 0);
        unordered_set<int> s(days.begin(), days.end());
        for (int i = 1; i < days.back()+1; ++i) {
            if (s.find(i) == s.end()) {
                dp[i] = dp[i-1];
            }
            else {
                int tmp1 = dp[i-1] + costs[0];
                int tmp2 = dp[max(i-7, 0)] + costs[1];
                int tmp3 = dp[max(i-30, 0)] + costs[2];
                dp[i] = min(tmp1, min(tmp2, tmp3));
            }
        }
        return dp.back();
    }
};
