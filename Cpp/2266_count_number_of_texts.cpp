// https://leetcode.cn/problems/count-number-of-texts/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countTexts(string pressedKeys) {
        int n = pressedKeys.size(), MOD = 1e9 + 7;
        vector<long long> dp(n+1, 1);
        int cnt = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i-1];
            char cur = pressedKeys[i-1];
            if (cur != pressedKeys[i-2]) {
                cnt = 1;
                continue;
            }
            cnt += 1;
            int cnt_max = (cur != '7' && cur != '9') ? 3 : 4;
            for (int k = 2; k <= min(cnt, cnt_max); ++k) {
                dp[i] = (dp[i] + dp[i-k]) % MOD;
            }
        }
        return dp.back();
    }
};

int main() {
    Solution sol;
    string pressedKeys = "22233";
    cout << sol.countTexts(pressedKeys) << '\n';
    return 0;
}
