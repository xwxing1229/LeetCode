// https://leetcode.cn/problems/ugly-number/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1, 1);
        int p2 = 1, p3 = 1, p5 = 1;
        for (int i = 2; i < n+1; ++i) {
            int num2 = dp[p2] * 2;
            int num3 = dp[p3] * 3;
            int num5 = dp[p5] * 5;
            dp[i] = min(num2, min(num3, num5));

            if (dp[i] == num2) {
                p2 = p2 + 1;
            }
            if (dp[i] == num3) {
                p3 = p3 + 1;
            }
            if (dp[i] == num5) {
                p5 = p5 + 1;
            }
        }
        return dp[n];
    }
};
