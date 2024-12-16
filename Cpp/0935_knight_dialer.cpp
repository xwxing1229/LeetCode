// https://leetcode.cn/problems/knight-dialer/

class Solution {
public:
    int knightDialer(int n) {
        auto invalid = [](int i, int j) {
            return i == 3 && (j == 0 || j == 2);
        };

        int MOD = 1e9 + 7;
        vector<pair<int,int>> dirs = {
            {1,2}, {1,-2}, {-1,2}, {-1,-2},
            {2,1}, {2,-1}, {-2,1}, {-2,-1}
        };

        vector<vector<vector<long>>> dp(n, vector<vector<long>>(8, vector<long>(7, 0)));
        for (int i = 2; i < 6; ++i) {
            for (int j = 2; j < 5; ++j) {
                if (invalid(i-2, j-2)) continue;
                dp[0][i][j] = 1;
            }
        }

        for (int k = 1; k < n; ++k) {
            for (int i = 2; i < 6; ++i) {
                for (int j = 2; j < 5; ++j) {
                    if (invalid(i-2, j-2)) continue;
                    long tmp = 0;
                    for (auto &d: dirs) {
                        tmp = (tmp + dp[k-1][i+d.first][j+d.second]) % MOD;
                    }
                    dp[k][i][j] = tmp;
                }
            }
        }

        int res = 0;
        for (auto &row: dp[n-1]) {
            for (long val: row) {
                res = (val + res) % MOD;
            }
        }
        return res;
    }
};
