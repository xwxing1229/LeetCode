// https://leetcode.cn/problems/maximum-amount-of-money-robot-can-earn/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<int>> dp(n, {INT_MIN, INT_MIN, INT_MIN});
        dp[0] = {0, 0, 0};
        for (int i = 0; i < m; ++i) {
            vector<int> prev = {INT_MIN, INT_MIN, INT_MIN};
            for (int j = 0; j < n; ++j) {
                int c = coins[i][j];
                dp[j][2] = max(max(dp[j][1], prev[1]),
                                max(dp[j][2], prev[2]) + c);
                dp[j][1] = max(max(dp[j][0], prev[0]),
                                max(dp[j][1], prev[1]) + c);
                dp[j][0] = max(dp[j][0], prev[0]) + c;
                prev = dp[j];
            }
        }
        const auto &res = dp.back();
        return max(res[0], max(res[1], res[2]));
    }
};

int main() {
    Solution sol;
    vector<vector<int>> coins = {
        {0,  1, -1},
        {1, -2,  3},
        {2, -3,  4}
    };
    cout << sol.maximumAmount(coins) << '\n';
    return 0;
}