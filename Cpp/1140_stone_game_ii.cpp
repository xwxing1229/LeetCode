// https://leetcode.cn/problems/stone-game-ii/

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size(), s = 0;
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        for (int i = n-1; i >= 0; --i) {
            s += piles[i];
            for (int m = 1; m <= i/2+1; ++m) {
                if (i + 2*m >= n) {
                    dp[i][m] = s;
                }
                else {
                    for (int x = 1; x <= 2*m; ++x) {
                        dp[i][m] = max(dp[i][m], s - dp[i+x][max(x,m)]);
                    }
                }
            }
        }
        return dp[0][1];
    }
};
