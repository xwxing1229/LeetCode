// https://leetcode.cn/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 0);
        for (int i = 1; i <= amount; ++i) {
            int tmp = amount + 1;
            for (int coin: coins) {
                int rem = i - coin;
                if (rem == 0) {
                    tmp = 0;
                }
                else if ((rem > 0) && (dp[rem] > 0)) {
                    tmp = min(tmp, dp[rem]);
                }
            }
            if (tmp == amount + 1) {
                dp[i] = -1;
            }
            else {
                dp[i] = tmp + 1;
            }
        }
        return dp[amount];
    }
};
