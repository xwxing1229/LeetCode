// https://leetcode.cn/problems/minimum-number-of-coins-for-fruits/

#include <iostream>
#include <vector>

using namespace std;
        
class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        // dp[i][0]: minimum number of coins until the ith fruit without buying the ith fruit.
        // dp[i][1]: minimum number of coins until the ith fruit with buying the ith fruit.
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2));
        dp[1][0] = prices[0];
        dp[1][1] = prices[0];
        for (int i = 2; i <= n; ++i) {
            dp[i][0] = dp[i-1][1];
            for (int j = (i+1)/2; j < i; ++j) {
                dp[i][0] = min(dp[i][0], dp[j][1]);
            }
            dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + prices[i-1];
        }
        return min(dp.back()[0], dp.back()[1]);
    }
};

int main() {
    Solution sol;
    vector<int> prices = {1,10,1,1}; // 2
    cout << sol.minimumCoins(prices) << '\n';
    return 0;
}