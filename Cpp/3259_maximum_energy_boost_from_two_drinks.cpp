// https://leetcode.cn/problems/maximum-energy-boost-from-two-drinks/

class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        return max(f(energyDrinkA, energyDrinkB), f(energyDrinkB, energyDrinkA));
    }

    long long f(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector<pair<long long, long long>> dp(n+1, make_pair(0, 0));
        for (int i = 0; i < n; ++i) {
            int a = energyDrinkA[i], b = energyDrinkB[i];
            dp[i+1].first = max(dp[i].first + a, dp[i].second);
            dp[i+1].second = max(dp[i].first, dp[i].second + b);
        }
        return max(dp[n].first, dp[n].second);
    }
};
