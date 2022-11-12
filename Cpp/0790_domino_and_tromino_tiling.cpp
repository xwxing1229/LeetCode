// https://leetcode.cn/problems/domino-and-tromino-tiling/

class Solution {
public:
    int numTilings(int n) {
        // dp[i][0]: in the ith column, no tile
        // dp[i][1]: in the ith column, only 1 tile in the 1st row
        // dp[i][2]: in the ith column, only 1 tile in the 2nd row
        // dp[i][3]: in the ith column, 2 tiles in both rows
        if (n == 1) return 1;
        if (n == 2) return 2;

        vector<vector<long>> dp(n, vector<long>(4,1));
        dp[1][3] = 2;
        for (int i = 2; i < n; ++i) {
            dp[i][0] = dp[i-1][3];
            dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % 1000000007;
            dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % 1000000007;
            dp[i][3] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2] + dp[i-1][3]) % 1000000007;
        }
        return dp[n-1][3];
    }
};
