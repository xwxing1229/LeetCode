// https://leetcode.cn/problems/stone-game-iii/

#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n+1, INT_MIN);
        dp.back() = 0;
        for (int i = n-1; i >= 0; --i) {
            int s = 0;
            for (int j = i; j < min(i+3, n); ++j) {
                s += stoneValue[j];
                dp[i] = max(dp[i], s - dp[j+1]);
            }
        }
        if (dp[0] > 0) return "Alice";
        else if (dp[0] == 0) return "Tie";
        else return "Bob";
    }
};