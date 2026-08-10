// https://leetcode.cn/problems/stone-game-iv/

#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1, false);
        for (int i = 1; i <= n; ++i) {
            for (int x = 1; x <= sqrt(i); ++x) {
                if (!dp[i - x * x]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};