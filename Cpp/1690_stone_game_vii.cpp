// https://leetcode.cn/problems/stone-game-vii/

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> cumsum(n+1, 0);
        for (int i = 0; i < n; ++i) {
            cumsum[i+1] = cumsum[i] + stones[i];
        }
        
        vector<vector<int>> dp(n, vector<int>(n,0));
        for (int i = n-2; i >= 0; --i) {
            for (int j = i+1; j < n; ++j) {
                dp[i][j] = max(cumsum[j+1] - cumsum[i+1] - dp[i+1][j],
                               cumsum[j] - cumsum[i] - dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};
